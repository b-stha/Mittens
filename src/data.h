#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <string>
#include <vector>
#include <dpp/dpp.h>

std::unordered_map<std::string, std::string> unitEmotes;
std::unordered_map<std::string, std::string> itemEmotes;
std::unordered_map<std::string, std::vector<std::string>> augmentEmotes;
std::unordered_map<std::string, std::vector<std::string>> rankEmotes;
std::unordered_map<std::string, uint32_t> rankEmotes;
std::unordered_map<int, std::string> placementEmotes;
std::unordered_map<std::string, std::string> traitEmotes;
std::string defaultEmote = "<:steamhappy:1123798178030964848>";
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
