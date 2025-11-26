#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <string>
#include <vector>
#include <dpp/dpp.h>

std::unordered_map<std::string, std::vector<std::string>> augmentEmotes;
std::unordered_map<std::string, std::unordered_map<int, std::string>> traitEmotes;

std::string defaultEmote = "<:steamhappy:1123798178030964848>";

std::unordered_map<std::string, std::vector<std::string>> rankData;
std::unordered_map<std::string, uint32_t> rankColor;
std::unordered_map<int, std::string> placementData;
struct TraitInfo {
	std::string name;
	std::vector<int> breakpoints;
	std::unordered_map<int, std::string> styles;
};
struct UnitInfo {
	std::string name;
	int rarity;
	std::string emote;
};

struct CDragonData{
    std::unordered_map<std::string, TraitInfo> traitData;
    std::unordered_map<std::string, UnitInfo> unitData;
};

#endif
