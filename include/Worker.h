#ifndef WORKER_H
#define WORKER_H

#include <queue>

class Player;
class Riot;
class Data;
class Bot;

class Worker {
public:
    void startTask();
    void finishTask();
    void enqueue(Player* player);
    Worker(Bot* bot, Data* data)
        : mittens(bot), loadedData(data) {}
private:
	bool isRunning = false;
    std::queue<Player*> playerQueue;
    Bot* mittens;
    Data* loadedData;
};

#endif