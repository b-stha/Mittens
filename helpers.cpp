#include "helpers.h"

std::string operator * (std::string a, unsigned int b) {
	std::string output = "";
	while (b--) {
		output += a;
	}
	return output;
}

std::string setStrWidth(const std::string& str, int len) {
	std::string result = str;
	int spaces_to_add = len - str.length();
	for (int i = 0; i < spaces_to_add; ++i) {
		result += " "; // Regular space
	}
	return result;
}

std::string starCount(const int& tier) {
	std::string star = ":star:";
	return (star * tier);
};

std::string itemListStr(const Unit& unit) {
	std::string itemListOutput = "";
	std::string emptyItem = "<:transparent:1250910469330567292> ";
	if (unit.items.empty()) {
		itemListOutput += (emptyItem * 3);
	}
	else {
		for (const auto& item : unit.items) {
			itemListOutput += itemData.at(item) + " ";
		}
	}
	return itemListOutput;
}