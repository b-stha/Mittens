#include "header.hpp"
#include <cmath>
#include <dpp/dpp.h>

using json = nlohmann::json;

const std::string BOT_TOKEN = "MTI0ODg2NzYwMDQ0MDc1ODM2NQ.Gm3k1c.mUTjgUzPVocwDVTknVzNHDF15MUy2RaD3nwpwU";
const std::string MY_GUILD_ID = "1249287556638445658";
const std::string TFT_APIKEY = "RGAPI-4b0c9171-f528-4da8-a8c6-39b9805102db";
const std::string puuid = "0mIwh5itpbxbDmP7-cON6UG1mx-n518iW2ynO3U9r2s3GGv4h99GAEgwh_f-llq595guEmcS133FTQ";

int main() {
    dpp::cluster bot(BOT_TOKEN);
    std::string matchIDurl = "https://americas.api.riotgames.com/tft/match/v1/matches/by-puuid/" + puuid + "/ids?count=1&api_key=" + TFT_APIKEY;
    cpr::Response matchIDr = cpr::Get(cpr::Url{ matchIDurl });
    std::string matchID = "";
    std::string userName;
    std::string tagLine;
    json matchIDresponse;

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

    try {
        json matchIDresponse = json::parse(matchIDr.text);
        matchID = matchIDresponse[0];
    }
    catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::exception& e) {
        std::cerr << "JSON error: " << e.what() << std::endl;
        return 1;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::string matchInfoURL = "https://americas.api.riotgames.com/tft/match/v1/matches/" + matchID + "?api_key=" + TFT_APIKEY;
    cpr::Response matchInfoR = cpr::Get(cpr::Url{ matchInfoURL });

    if (matchInfoR.error) {
        std::cerr << "Request error: " << matchInfoR.error.message << std::endl;
        return 1;
    }

    if (matchInfoR.status_code != 200) {
        std::cerr << "Failed to get data: " << matchInfoR.status_code << std::endl;
        return 1;
    }

    try {
        matchIDresponse = json::parse(matchInfoR.text);

        std::cout << matchIDresponse.dump(4) << std::endl;

    }
    catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::exception& e) {
        std::cerr << "JSON error: " << e.what() << std::endl;
        return 1;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    std::string userNameURL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-puuid/" + puuid + "?api_key=" + TFT_APIKEY;
    cpr::Response userNameURL = cpr::Get(cpr::Url{ userNameURL });

    try {
        json userNameResponse = json::parse(userNameURL);
        userName = userNameResponse[0];
        tagLine = userNameResponse[1];
    }
    catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::exception& e) {
        std::cerr << "JSON error: " << e.what() << std::endl;
        return 1;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }


    double gameLength = matchIDresponse["info"]["game_length"] / 60.0;

    double mins, secs;
    secs = modf(gameLength, &mins) * 60;
    std::cout << "Duration: " << mins << ":" << static_cast<int>(secs) << '\n' << std::endl;

    Info info = matchIDresponse["info"];
    std::vector<Participant> participants = matchIDresponse["info"]["participants"];

    Participant me = findP(info, puuid);


    std::cout << "Augments: \n" << me.augments[0] << '\n' << me.augments[1] << '\n' << me.augments[2] << std::endl;

    std::string tacticsToolsURL = "https://tactics.tools/player/na/" + userName + "/" + tagLine;

    dpp::embed embed = dpp::embed()
        .set_color(dpp::colors::sti_blue)
        .set_title("MK's latest match")
        .set_url(tacticsToolsURL);
    return 0;
}
