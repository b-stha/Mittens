#include "Player.h"
#include "RiotAPI.h"
#include "parsejson.h"
#include "bot.h"
#include "helpers.h"
#include "apikeys.h"
#include <dpp/dpp.h>
#include <atomic>
#include <memory>

using json = nlohmann::json;

std::atomic <bool> running = false;
std::vector<std::unique_ptr<Player>> userVec;

void stop() {
    running = false;
}

int main() {
    dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));

            dpp::slashcommand add;
            add.set_name("add");
            add.set_description("Format as name#tagline.");
            add.add_option(
                dpp::command_option(dpp::co_string, "username", "name#tag", true)
            );

            bot.global_command_create(add, [&](const dpp::confirmation_callback_t& callback) {
                if (callback.is_error()) {
                    std::cout << callback.http_info.body << "\n";
                }
                });
        }
    });

    bot.on_slashcommand([&bot](const dpp::interaction_create_t& event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
            dpp::snowflake currChannel = event.command.channel_id;

            if (cmd_data.name == "add") {
                std::string userInput = std::get<std::string>(cmd_data.options[0].value);
                std::cout << userInput << std::endl;
                std::vector<std::string> userInputArr;

                if (userInput.find("#") != std::string::npos) { 
                    userInputArr = split(userInput, '#');
                }
                else {
                    userInputArr.emplace_back(userInput);
                    userInputArr.emplace_back("NA1");
                }
                
                std::string puuid;

                bool puuidFetchSuccess = false;

                try {
                    puuid = fetchPUUID(userInputArr[0], userInputArr[1], TFT_APIKEY);
                    puuidFetchSuccess = true;
                    event.reply(userInput + " successfully added");
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                    event.reply(userInput + " not found...");
                }

                if (puuidFetchSuccess && notPlayerExists(userVec, puuid)) {
                    std::unique_ptr pPlayer = std::make_unique<Player>(puuid);
                    pPlayer->setChannelID(currChannel);
                    pPlayer->setNameTag(userInputArr[0], userInputArr[1]);
                    userVec.push_back(std::move(pPlayer));
                }
                else {
                    event.reply(userInput + " already exists.");
                }
            }
        }
    });

    bot.start(dpp::st_return);

    signal(SIGINT, [](int code) {
        stop();
        });

    running = true;

    try {
            while (running) {
            if (!userVec.empty()) {
                for (auto& user : userVec)
                {
                    std::string checkMatch = fetchMatchID(*user, TFT_APIKEY);
                    if (user->getCurrMatch() != checkMatch) {
                        user->setprevMatch(user->getCurrMatch());
                        user->setCurrMatch(checkMatch);
                        Info updatedInfo = fetchInfo(user->getCurrMatch(), TFT_APIKEY);
                        user->setMatchInfo(updatedInfo);
                        dpp::embed embOutput = createResult(*user);
                        dpp::message msg(user->getChannelID(), embOutput);
                        bot.message_create(msg);
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(10));
        };
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
