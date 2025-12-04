#ifndef WORKER_H
#define WORKER_H

#include <queue>
#include "Player.h"
#include "RiotAPI.h"
#include "data.h"
#include "bot.h"

class Worker {
public:
    void startTask();
    void finishTask();
    void enqueue(Player* player);
    Worker(Riot* api, Bot* bot, Data* data)
        : riotAPI(api), mittens(bot), loadedData(data) {}
private:
	bool isRunning = false;
    std::queue<Player*> playerQueue;
    Riot* riotAPI;
    Bot* mittens;
    Data* loadedData;
};

#endif