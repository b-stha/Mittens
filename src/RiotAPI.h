#ifndef RIOTAPI_H
#define RIOTAPI_H

#include <string>
#include "Player.h"

class RiotAPI {
public:
    RiotAPI(dpp::cluster* bot, const std::string& apiKey)
        : botCluster(bot), apiKey(apiKey) {}
    void fetchMatchID(Player& player, std::function<void()> next = {});
    void fetchInfo(Player& player, std::function<void()> next = {});
    void setName(Player& player);
    void fetchPUUID(const std::string& name, const std::string& tag, std::function<void(const std::string&)> next = {});
    void fetchSummonerID(const Player& player);
    void fetchLeague(Player& player);

private:
    dpp::cluster* botCluster;
    std::string apiKey;
};

#endif

