#ifndef RIOTAPI_H
#define RIOTAPI_H

#include "parsejson.h"
#include "helpers.h"

std::string fetchMatchID(const Player& player, const std::string apiKey);
Info fetchInfo(const std::string matchID, const std::string apiKey);
void setName(Player& player, const std::string apiKey);
std::string fetchPUUID(const std::string& name, const std::string& tag, const std::string& apiKey);

#endif

