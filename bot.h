#ifndef BOT_H
#define BOT_H

#include <dpp/dpp.h>
#include "Player.h"
#include "data.h"

std::string operator * (std::string a, unsigned int b);
std::string itemListStr(const Player& player);
std::string starCount(const int& tier);
std::string unitListStr(const Player& player);
dpp::embed createResult(const Player& player);

#endif
