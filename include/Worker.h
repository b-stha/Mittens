#ifndef WORKER_H
#define WORKER_H

#include <queue>
#include <memory>
#include <mutex>
#include <unordered_set>

class Player;
class Riot;
class Data;
class Bot;

class Worker {
public:
    void startTask();
    void finishTask();
    std::shared_ptr<Data> getData() const;
    bool enqueue(const std::shared_ptr<Player>& player);
    Worker(Bot* bot)
        : pMittens(bot) {}
private:
    std::unordered_set<std::string> queuedOrRunningPuuids;
    std::string activePuuid; 
	bool isRunning = false;
    std::queue<std::shared_ptr<Player>> playerQueue;
    std::mutex queueMutex;
    Bot* pMittens;
};

#endif