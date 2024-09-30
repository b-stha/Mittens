#ifndef TRAITS_H
#define TRAITS_H

#include <unordered_map>
#include <string>

struct Trait {
	std::string name;
	int tierTotal = 0;
	std::unordered_map<int, std::string> breakpoints;
    Trait(std::string traitName, int maxTier);
};

extern const std::unordered_map<std::string, Trait> traitList;

#endif