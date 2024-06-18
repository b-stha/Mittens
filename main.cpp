#include "Player.h"
#include "RiotAPI.h"
#include "parsejson.h"
#include "bot.h"
#include <dpp/dpp.h>
#include <atomic>
#include "helpers.h"

using json = nlohmann::json;

const std::string BOT_TOKEN = "MTI0ODg2NzYwMDQ0MDc1ODM2NQ.Gm3k1c.mUTjgUzPVocwDVTknVzNHDF15MUy2RaD3nwpwU";
const std::string MY_GUILD_ID = "1249287556638445658";
const std::string TFT_APIKEY = "RGAPI-7b485cc9-db88-486b-bae3-6a784f6fc3e6";
const std::string puuid = "0mIwh5itpbxbDmP7-cON6UG1mx-n518iW2ynO3U9r2s3GGv4h99GAEgwh_f-llq595guEmcS133FTQ";
const dpp::snowflake CHANNEL_ID = 1251792647157317673;

std::atomic <bool> running = false;
std::vector<std::unique_ptr<Player>> userVec;

void stop() {
    running = false;
}

int main() {
    std::vector<std::unique_ptr<Player>> userVec;

    //TODO: include transparent and replace newlines with transparents

    dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event){
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
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
    });

    bot.on_interaction_create([&bot, &userVec](const dpp::interaction_create_t& event) {
        if (event.command.type == dpp::it_application_command) {
            dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);

            if (cmd_data.name == "add") {
                std::string userInput = cmd_data.options[0].name;
                std::vector<std::string> userInputArr = split(userInput, '#');
                bool puuidFetchSuccess = false;

                try {
                    std::string puuid = fetchPUUID(userInputArr[0], userInputArr[1], TFT_APIKEY);
                    puuidFetchSuccess = true;
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << std::endl;
                }

                if (puuidFetchSuccess) {
                    userVec.push_back(std::make_unique<Player>(puuid));
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
                        dpp::message_create_t(msg);
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
