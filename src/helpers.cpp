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
		result += " ";
	}
	return result;
}

std::string starCount(const int& tier) {
	std::string star = ":star:";
	return (star * tier);
};

std::string itemListStr(const Unit& unit) {
	std::string itemListOutput = "";
	std::string emptyItem = "<:transparent:1250910469330567292>";
	if (unit.items.empty()) {
		itemListOutput += (emptyItem * 3);
	}
	else {
		for (const auto& item : unit.items) {
            if (itemEmotes.count(item) > 0) {
			    itemListOutput += itemEmotes.at(item) + " "; 
                continue;
            }
            itemListOutput += "<:steamhappy:1123798178030964848>";
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
	int unitCount;
	for (auto unit : matchInfo.units) {
		if (unit.tier > 1) {
			unitCount = 3 * (unit.tier - 1);
		}
		else {
			unitCount = 1;
		}

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
		case 8:
			boardValue += 6 * unitCount;
			break;
		}
	}
	return boardValue;
}

std::string fillSpaces(std::string input) {
    std::string fillStr = "%20";
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            input.erase(i,1);
            input.insert(i, fillStr);
        }
    }
    return input;
}

int subtractLP(const Player& player) {
	if (player.getPlayerLP().first == 0) {
		return (player.getPlayerLP().second - 100);
	}

	return (player.getPlayerLP().second - player.getPlayerLP().first);
}

bool sortByStyle(const Trait& t1, const Trait& t2) {
	return t1.style > t2.style;
}



std::unique_ptr<CDragonData> loadJson() {
	const std::string filePath = "/home/MK/Documents/mittens/setdata.json"; // for emote IDs
	std::ifstream file(filePath);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file: " + filePath);
	}
	nlohmann::json emoteJson;
	file >> emoteJson;
	file.close();
	std::cout << "Loaded JSON data from " << filePath << std::endl;

	try {
		emoteJson["unitEmotes"].get_to(unitEmotes);
		emoteJson["itemEmotes"].get_to(itemEmotes);
		emoteJson["augmentEmotes"].get_to(augmentEmotes);
		emoteJson["rankEmotes"].get_to(rankEmotes);
		emoteJson["rankEmotes"].get_to(traitEmotes);
		emoteJson["placementEmotes"].get_to(placementEmotes);
	} catch (const nlohmann::json::exception& e) {
		throw std::runtime_error(std::string("JSON error while loading emote data: ") + e.what());
	}

	const std::string urlPath = "https://raw.communitydragon.org/pbe/cdragon/tft/en_us.json"; // for unit and traits
	nlohmann::json dataJson = makeReq(urlPath, 10, 1000);
	std::cout << "Fetched JSON data from " << urlPath << std::endl;
	
	std::unique_ptr<CDragonData> cdragonRT = std::make_unique<CDragonData>();
	std::string unitAPIName, unitDispName, traitAPIName, traitDispName;
	int latestSet = dataJson["sets"].size() - 1;
	for (auto& unit : dataJson["sets"][latestSet]["champions"]) {
        unitAPIName = unit["apiName"];
        unitDispName = unit["name"];

		UnitInfo unitInfo;
		unitInfo.name = unitDispName;
		unitInfo.rarity = unit["cost"] - 1;
		cdragonRT->unitData[unitAPIName] = unitInfo;
    }

	for (auto& trait : dataJson["sets"][latestSet]["traits"]) {
		traitAPIName = trait["apiName"];
		traitDispName = trait["name"];

		std::vector<int> traitLevels;

		for (auto& level : trait["effects"]) {
			traitLevels.push_back(level["minUnits"]);
		}

		TraitInfo traitInfo;
		traitInfo.name = traitDispName;
		traitInfo.breakpoints = traitLevels;
		cdragonRT->traitData[traitAPIName] = traitInfo;
    }

	return cdragonRT;
}