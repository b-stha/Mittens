#ifndef BOT_H
#define BOT_H

#include <dpp/dpp.h>
#include "Player.h"
#include "data.h"
#include "helpers.h"
#include <algorithm>

class Bot {
public:
    void unitListStr(const Player& player, dpp::embed& embedObj, const Data& data);
    void traitListStr(const Player& player, dpp::embed& embedObj, const Data& data);
    std::string itemListStr(const Unit& unit, const Data& data);
    std::string augListStr(const Player& player, const Data& data);
    dpp::embed createResult(const Player& player, const Data& data);
    dpp::embed createPromoMsg(const Player& player, const Data& data);
    void setRunning(bool state) { running.store(state); }
    std::atomic<bool> isRunning() const { return running.load(); }
    void run();
    Bot();
private:
    void registerCommands();
    void readyHandler();
    dpp::cluster botCluster;
    std::vector<std::unique_ptr<Player>> userVec;
    std::atomic <bool> running = false;
};

#endif
