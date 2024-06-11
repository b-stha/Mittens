#ifndef RIOTAPI_H
#define RIOTAPI_H

#include "parsejson.h"

std::string fetchMatchID(const Player& player, const std::string apiKey);
Info fetchInfo(const std::string matchID, const std::string apiKey);
void setName(Player& player, const std::string apiKey);

#endif

