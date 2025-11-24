#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <string>
#include <vector>
#include <dpp/dpp.h>
#include "Player.h"

extern const std::unordered_map<std::string, std::string> itemData;
extern const std::unordered_map<std::string, std::vector<std::string>> augmentData;
extern const std::unordered_map<std::string, std::vector<std::string>> rankData;
extern const std::unordered_map<std::string, uint32_t> rankColor;
extern const std::unordered_map<int, std::string> placementData;

struct TraitInfo {
	std::string name;
	std::vector<int> breakpoints;
};
struct UnitInfo {
	std::string name;
	int rarity;
};

struct CDragonData{
    std::unordered_map<std::string, TraitInfo> traitData;
    std::unordered_map<std::string, UnitInfo> unitData;
};

#endif
