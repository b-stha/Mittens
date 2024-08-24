#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <string>
#include <vector>

extern const std::unordered_map<std::string, std::vector<std::string>> unitData;
extern const std::unordered_map<std::string, std::string> itemData;
extern const std::unordered_map<std::string, std::vector<std::string>> augmentData;
extern const std::unordered_map<std::string, std::unordered_map<int, std::string>> traitData;

#endif
