#ifndef HELPERS_H
#define HELPERS_H

#include "Player.h"
#include "data.h"
#include <sstream>
#include <algorithm>
#include <fstream>
#include "parsejson.h"
#Include <type_traits>

std::string setStrWidth(const std::string& str, int len);
std::string operator * (std::string a, unsigned int b);
std::string itemListStr(const Unit& unit);
std::string starCount(const int& tier);
std::vector<std::string> split(const std::string& s, char delim);
bool notPlayerExists(const std::vector<std::unique_ptr<Player>>& players, const std::string& puuid);
int calcBoardValue(PlayerMatchInfo matchInfo);
std::string fillSpaces(std::string input);
int subtractLP(const Player& player);
bool sortByStyle(const Trait& t1, const Trait& t2);
template <typename valueType>
void loadEmoteJson(const nlohmann::json& emoteJson, const std::string& dataName, std::unordered_map<std::string, valueType>& toMap);
void loadCDragonData(CDragonData& dragon);
std::unique_ptr<CDragonData> loadJson();

#endif
