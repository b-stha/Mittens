#ifndef BOT_H
#define BOT_H

#include <dpp/dpp.h>
#include "Player.h"
#include "data.h"
#include "helpers.h"
#include <algorithm>

std::string augListStr(const Player& player);
void unitListStr(const Player& player, dpp::embed& embedObj, const CDragonData& dragon);
dpp::embed createResult(const Player& player, const CDragonData& dragon);
dpp::embed createPromoMsg(const Player& player);
#endif
