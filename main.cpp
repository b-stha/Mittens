#include "Player.h"
#include "RiotAPI.h"
#include "parsejson.h"
#include "bot.h"
#include <dpp/dpp.h>
#include <atomic>

using json = nlohmann::json;

const std::string BOT_TOKEN = "MTI0ODg2NzYwMDQ0MDc1ODM2NQ.Gm3k1c.mUTjgUzPVocwDVTknVzNHDF15MUy2RaD3nwpwU";
const std::string MY_GUILD_ID = "1249287556638445658";
const std::string TFT_APIKEY = "RGAPI-7b485cc9-db88-486b-bae3-6a784f6fc3e6";
const std::string puuid = "0mIwh5itpbxbDmP7-cON6UG1mx-n518iW2ynO3U9r2s3GGv4h99GAEgwh_f-llq595guEmcS133FTQ";
const dpp::snowflake CHANNEL_ID = 1251792647157317673;

std::atomic <bool> running = false;

void stop() {
    running = false;
}

int main() {
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
    
    Player me(puuid);

    std::string matchID = fetchMatchID(me, TFT_APIKEY);
    std::cout << matchID << std::endl;
    Info info = fetchInfo(matchID, TFT_APIKEY);

    me.setMatchInfo(info);

    Unit item1 = me.myMatchInfo.units[0];

    bot.on_slashcommand([&bot, &me](const dpp::slashcommand_t& addUserID) {
        dpp::command_interaction cmd_data = addUserID.command.get_command_interaction();

        if (addUserID.command.get_command_name() == "add") {
            auto subcommand = cmd_data.options[0]

            dpp::embed output = createResult(me);
            dpp::message msg(event.command.channel_id, output);

            event.reply(msg);
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("embed", "Send a test embed!", bot.me.id));
        }
        });

    bot.start(dpp::st_return);

    signal(SIGINT, [](int code) {
        stop();
        });

    running = true;

    try {
        while (running) {

            std::string checkMatch = fetchMatchID(me, TFT_APIKEY);
            if (me.getCurrMatch() != checkMatch) {
                me.setprevMatch(me.getCurrMatch());
                me.setCurrMatch(checkMatch);
                Info updatedInfo = fetchInfo(me.getCurrMatch(), TFT_APIKEY);

                me.setMatchInfo(updatedInfo);
                dpp::embed embOutput = createResult(me);

                dpp::message msg(CHANNEL_ID, embOutput);
                dpp::message_create_t(msg);
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
