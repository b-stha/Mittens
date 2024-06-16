#ifndef BOT_H
#define BOT_H

#include <dpp/dpp.h>
#include "Player.h"
#include "data.h"

std::string operator * (std::string a, unsigned int b);
std::string itemListStr(const Unit& unit);
std::string starCount(const int& tier);
void unitListStr(const Player& player, dpp::embed& embedObj);
dpp::embed createResult(const Player& player);
std::string setStrWidth(const std::string& str, int len);
#endif
