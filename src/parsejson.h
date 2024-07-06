#ifndef PARSEJSON_H
#define PARSEJSON_H

#include "Player.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <algorithm>
#include <fstream>

using json = nlohmann::json;

void from_json(const json& j, Trait& t);

void from_json(const json& j, Unit& u);

void from_json(const json& j, PlayerMatchInfo& p);

void from_json(const json& j, Info& i);

json parseJSON(cpr::Response r);
#endif