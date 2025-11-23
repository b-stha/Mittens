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
struct RuntimeData{
    std::unordered_map<std::string, std::unordered_map<int, std::string>> traitStyles;
    std::unordered_map<std::string, std::string> unitData;
};

#endif
