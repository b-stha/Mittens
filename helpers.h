#ifndef HELPERS_H
#define HELPERS_H

#include "Player.h"
#include "data.h"

std::string setStrWidth(const std::string& str, int len);
std::string operator * (std::string a, unsigned int b);
std::string itemListStr(const Unit& unit);
std::string starCount(const int& tier);

#endif
