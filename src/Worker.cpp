#include "Worker.h"
#include "Player.h"
#include "RiotAPI.h"
#include "data.h"
#include "bot.h"

void Worker::startTask() {
    if (isRunning && playerQueue.empty()) {
        return;
    }

    isRunning = true;
    Player* currPlayer = playerQueue.front();
    playerQueue.pop();

    pMittens->getRiotObj().fetchMatchID(*currPlayer, [this, currPlayer]() {
        pMittens->getRiotObj().fetchLeague(*currPlayer, [this, currPlayer]() {
            pMittens->getRiotObj().fetchInfo(*currPlayer, [this, currPlayer]() {
                auto data = this->getData();
                dpp::embed embOutput = pMittens->createResult(*currPlayer, *data);
                dpp::message msg(currPlayer->getChannelID(), embOutput);
                pMittens->getBotCluster().message_create(msg);

                if (currPlayer->getPlayerRank().first != currPlayer->getPrevRank()) {
                    dpp::embed promoMsg = pMittens->createPromoMsg(*currPlayer, *data);
                    dpp::message promoMsgObj(currPlayer->getChannelID(), promoMsg);
                    pMittens->getBotCluster().message_create(promoMsgObj);
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

const std::shared_ptr<Data>& Worker::getData() const {
    return pMittens->getLoadedData();
}

void Worker::enqueue(Player* player) {
    playerQueue.push(player);
}
