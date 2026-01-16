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
                int currQueueID = currPlayer->getMatchInfo().queueID;
                std::unordered_set<int> addedQueues = currPlayer->getAddedQueues();
                if (addedQueues.contains(currQueueID)) {
                    switch (currQueueID) {
                        case 1100: // ranked
                            pMittens->createRankedEmbed(*currPlayer, *data);
                            break;
                        case 1160: // double up
                            pMittens->createDoubleUpEmbed(*currPlayer, *data);
                            break;
                        default: // unranked
                            pMittens->createUnrankedEmbed(*currPlayer, *data);
                            break;
                    }
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
