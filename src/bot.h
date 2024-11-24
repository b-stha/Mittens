#ifndef BOT_H
#define BOT_H

#include <dpp/dpp.h>
#include "Player.h"
#include "data.h"
#include "helpers.h"
#include <algorithm>

std::string augListStr(const Player& player);
void unitListStr(const Player& player, dpp::embed& embedObj);
dpp::embed createResult(const Player& player);

#endif
