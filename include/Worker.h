#ifndef WORKER_H
#define WORKER_H

#include <queue>
#include <memory>

class Player;
class Riot;
class Data;
class Bot;

class Worker {
public:
    void startTask();
    void finishTask();
    const std::shared_ptr<Data>& getData() const;
    void enqueue(Player* player);
    Worker(Bot* bot)
        : pMittens(bot) {}
private:
	bool isRunning = false;
    std::queue<Player*> playerQueue;
    Bot* pMittens;
};

#endif