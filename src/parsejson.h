#ifndef PARSEJSON_H
#define PARSEJSON_H

#include "Player.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void from_json(const json& j, Trait& t);

void from_json(const json& j, Unit& u);

void from_json(const json& j, PlayerMatchInfo& p);

void from_json(const json& j, Info& i);

void from_json(const json& j, League& l);

json parseJSON(const cpr::Response& response);

json makeReq(const std::string& url, int maxTries, int delayMs);
#endif
