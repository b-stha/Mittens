#include "Worker.h"  

void Worker::startTask() {
    if (isRunning && playerQueue.empty()) {
        return;
    }

    isRunning = true;
    Player* currPlayer = playerQueue.front();
    playerQueue.pop();

    riotAPI->fetchMatchID(*currPlayer, [this, currPlayer]() {
        currPlayer->updateLP(); // care this step
        riotAPI->fetchLeague(*currPlayer, [this, currPlayer]() {
            riotAPI->fetchInfo(*currPlayer, [this, currPlayer]() {
                dpp::embed embOutput = mittens->createResult(*currPlayer, *loadedData);
                dpp::message msg(currPlayer->getChannelID(), embOutput);
                mittens->getBotCluster().message_create(msg);

                if (currPlayer->getPlayerRank().first != currPlayer->getPrevTier()) {
                    dpp::embed promoMsg = mittens->createPromoMsg(*currPlayer, *loadedData);
                    dpp::message promoMsgObj(currPlayer->getChannelID(), promoMsg);
                    mittens->getBotCluster().message_create(promoMsgObj);
                }
                finishTask();
            });
        });
    });
}

void Worker::finishTask() {
    isRunning = false;
    if (!playerQueue.empty()) {
        startTask();
    }
}

void Worker::enqueue(Player* player) {
    playerQueue.push(player);
}
