#include "Player.h"
#include "RiotAPI.h"
#include "parsejson.h"
#include "bot.h"
#include "apikeys.h"
#include <dpp/dpp.h>
#include <atomic>
#include <memory>

using json = nlohmann::json;
std::atomic <bool> running = false;
std::unique_ptr<Data> loadedData;

void stop() {
    running = false;
}

int main() {
    try {
        loadedData = std::make_unique<Data>();
    } catch (const std::exception& e) {
        std::cerr << "Error loading data: " << e.what() << std::endl;
        return 1;
    }
    
    Bot mittens;

    signal(SIGINT, [](int code) {
        running = false;
        });

    running = true;
    auto playerList = mittens.getUserVec();
    auto &bot = mittens.getBotCluster();
    try {
            while (running) {
            if (!playerList.empty()) {
                for (auto& user : playerList)
                {
                    user->setPrevTier(user->getPlayerRank().first);
                    std::string checkMatch = fetchMatchID(*user, TFT_APIKEY);
                    user->updateLP();
                    League playerLeague = fetchLeague(*user, TFT_APIKEY);

                    user->setPlayerRank(playerLeague);

                    if (user->getCurrMatch() != checkMatch) {
                        user->setprevMatch(user->getCurrMatch());
                        user->setCurrMatch(checkMatch);
                        Info updatedInfo = fetchInfo(user->getCurrMatch(), TFT_APIKEY);
                        user->setMatchInfo(updatedInfo);
                        dpp::embed embOutput = mittens.createResult(*user, *loadedData);
                        dpp::message msg(user->getChannelID(), embOutput);
                        bot.message_create(msg);
                    }

                    if (user->getPlayerRank().first != user->getPrevTier()) {
                        dpp::embed promoMsg = mittens.createPromoMsg(*user, *loadedData);
                        dpp::message msg(user->getChannelID(), promoMsg);
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
