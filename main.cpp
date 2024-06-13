#include "Player.h"
#include "RiotAPI.h"
#include "parsejson.h"
#include <dpp/dpp.h>

using json = nlohmann::json;

const std::string BOT_TOKEN = "MTI0ODg2NzYwMDQ0MDc1ODM2NQ.Gm3k1c.mUTjgUzPVocwDVTknVzNHDF15MUy2RaD3nwpwU";
const std::string MY_GUILD_ID = "1249287556638445658";
const std::string TFT_APIKEY = "RGAPI-2a3e681d-e5a3-411b-aca2-6946243dd526";
const std::string puuid = "0mIwh5itpbxbDmP7-cON6UG1mx-n518iW2ynO3U9r2s3GGv4h99GAEgwh_f-llq595guEmcS133FTQ";

int main() {
    /*
    dpp::cluster bot(BOT_TOKEN);

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

    dpp::embed embed = dpp::embed()
        .set_color(dpp::colors::sti_blue)
        .set_title("MK's latest match")
        .set_url(tacticsToolsURL);
    */

    Player me(puuid);

    std::string matchID = fetchMatchID(me, TFT_APIKEY);
    std::cout << matchID << std::endl;
    Info info = fetchInfo(matchID, TFT_APIKEY);

    me.setMatchInfo(info);
    std::cout << me.myMatchInfo.augments[0] << std::endl;

    return 0;
}
