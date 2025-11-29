#ifndef HELPERS_H
#define HELPERS_H

#include "Player.h"
#include "data.h"
#include <string>

std::string setStrWidth(const std::string& str, int len);
std::string operator * (std::string a, unsigned int b);
std::string starCount(const int& tier);
std::vector<std::string> split(const std::string& s, char delim);
bool notPlayerExists(const std::vector<std::unique_ptr<Player>>& players, const std::string& puuid);
std::string fillSpaces(std::string input);
int subtractLP(const Player& player);
bool sortByStyle(const Trait& t1, const Trait& t2);

#endif
