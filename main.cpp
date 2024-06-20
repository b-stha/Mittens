#include "Player.h"
#include "RiotAPI.h"
#include "parsejson.h"
#include "bot.h"
#include "helpers.h"
#include <dpp/dpp.h>
#include <atomic>
#include <memory>

using json = nlohmann::json;

const std::string BOT_TOKEN = "MTI0ODg2NzYwMDQ0MDc1ODM2NQ.Gm3k1c.mUTjgUzPVocwDVTknVzNHDF15MUy2RaD3nwpwU";
const std::string MY_GUILD_ID = "1249287556638445658";
const std::string TFT_APIKEY = "RGAPI-0d74ae74-25d9-4b1e-ad84-64f32881c6a9";
const dpp::snowflake CHANNEL_ID = 1251792647157317673;

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

            if (cmd_data.name == "add") {
                std::string userInput = std::get<std::string>(cmd_data.options[0].value);
                std::vector<std::string> userInputArr = split(userInput, '#');
                std::cout << userInput << std::endl;
                std::string puuid;

                bool puuidFetchSuccess = false;

                try {
                    puuid = fetchPUUID(userInputArr[0], userInputArr[1], TFT_APIKEY);
                    puuidFetchSuccess = true;
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }

                if (puuidFetchSuccess && playerExists(userVec, puuid)) {
                    userVec.push_back(std::make_unique<Player>(puuid));
                }
                else {
                    std::cout << "Player already exists." << std::endl;
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

                        dpp::message msg(CHANNEL_ID, embOutput);
                        bot.message_create(msg);
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(30));
        };
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
