#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <string>
#include <vector>
#include <dpp/dpp.h>
#include "Player.h"

std::unordered_map<std::string, std::vector<std::string>> unitData;
const std::unordered_map<std::string, std::string> itemData;
const std::unordered_map<std::string, std::vector<std::string>> augmentData;
const std::unordered_map<std::string, std::vector<std::string>> rankData;
const std::unordered_map<std::string, uint32_t> rankColor;
const std::unordered_map<int, std::string> placementData;
const std::unordered_map<std::string, TraitTemplate> traitData;

#endif
