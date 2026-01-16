#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>
#include <memory>

class Player;
class Data;

std::string setStrWidth(const std::string& str, int len);
std::string operator * (std::string a, unsigned int b);
std::string starCount(const int& tier);
std::vector<std::string> split(const std::string& s, char delim);
bool notPlayerExists(const std::vector<std::shared_ptr<Player>>& players, const std::string& puuid);
std::string fillSpaces(std::string input);
std::string getRankField(const Player& player, const Data& data, std::string queueType);
std::string lowerCase(std::string str);

#endif
