#ifndef BOT_H
#define BOT_H

#include <dpp/dpp.h>
#include "RiotAPI.h"

class Data;
class Player;

class Bot {
public:
    Bot();
    dpp::cluster& getBotCluster() { return botCluster; }
    Riot& getRiotObj() { return riotAPI; }
    const std::vector<std::unique_ptr<Player>>& getUserVec() const { return userVec; }
    void unitListStr(const Player& player, dpp::embed& embedObj, const Data& data);
    void traitListStr(const Player& player, dpp::embed& embedObj, const Data& data);
    std::string augListStr(const Player& player, const Data& data);
    dpp::embed createResult(const Player& player, const Data& data);
    dpp::embed createPromoMsg(const Player& player, const Data& data);
    void run();
private:
    void registerCommands();
    void readyHandler();
    dpp::cluster botCluster;
    Riot riotAPI;
    std::vector<std::unique_ptr<Player>> userVec;
};

#endif
