#include "helpers.h"
#include <sstream>
#include <algorithm>

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

std::vector<std::string> split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

bool notPlayerExists(const std::vector<std::unique_ptr<Player>>& players, const std::string& puuid) {
	return std::none_of(players.begin(), players.end(),
		[&puuid](const std::unique_ptr<Player>& player) {
			return player->getPUUID() == puuid;
		});
}

int calcBoardValue(PlayerMatchInfo matchInfo) {
	int boardValue = 0;
	for (auto unit : matchInfo.units) {
		int unitCount = 3 * unit.tier;
		switch (unit.rarity)
		{
		case 0:
			boardValue += 1 * unitCount;
			break;
		case 1:
			boardValue += 2 * unitCount;
			break;
		case 2:
			boardValue += 3 * unitCount;
			break;
		case 4:
			boardValue += 4 * unitCount;
			break;
		case 6:
			boardValue += 5 * unitCount;
			break;
		}
	}
	return boardValue;
}