#include "data.h"
#include "parsejson.h"
#include <fstream>

const nlohmann::json* Data::getObj(const nlohmann::json& j, const std::string& key) const {
	if (j.contains(key) && j[key].is_object()) {
		return &j[key];
	}
	return nullptr;
}

std::optional<std::string> Data::getJsonStr(const nlohmann::json& j, const std::string& key) const {
	if (j.contains(key) && j[key].is_string()) {
		return j[key].get<std::string>();
	}
	return std::nullopt;
}

std::optional<int> Data::getJsonInt(const nlohmann::json& j, const std::string& key) const{
	if (j.contains(key) && j[key].is_number_integer()) {
		return j[key].get<int>();
	}
	return std::nullopt;
}

CDragonData Data::loadCDragonData(const nlohmann::json& emoteJson) {
	nlohmann::json dataJson;
	std::string urlPath = "https://raw.communitydragon.org/pbe/cdragon/tft/en_us.json";
	try {
		dataJson = makeReq(urlPath, 10, 1000);
		std::cout << "Fetched JSON data from " << urlPath << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error(std::string("Error fetching data from Community Dragon: ") + e.what());
	}

	std::cout << "Enter set number to load (e.g., \"11\", \"12\"): ";
	std::string latestSet;
	std::getline(std::cin, latestSet);
	std::unordered_map<std::string, UnitInfo> unitData = loadUnitData(emoteJson, dataJson, latestSet);
	std::unordered_map<std::string, TraitInfo> traitData = loadTraitData(emoteJson, dataJson, latestSet);

	return CDragonData(traitData, unitData);
}

void Data::loadJson() {
	const std::string filePath = "/home/MK/Documents/mittens/setdata.json"; // for emote IDs
	std::ifstream file(filePath);
	if (!file.is_open()) {
		throw std::runtime_error("Error opening setdata.json");
	}

	nlohmann::json emoteJson;
	file >> emoteJson;
	file.close();
	std::cout << "Loaded JSON data from " << filePath << std::endl;
	
	auto itemEmotesObj = getObj(emoteJson, "itemEmotes");
	if (!itemEmotesObj) {
		throw std::runtime_error("itemEmotes object not found in setdata.json");
	} else {
		for (auto& [key, value] : itemEmotesObj->items()) {
			auto emoteID = getJsonStr(*itemEmotesObj, key);
			itemEmotes[key] = emoteID.value_or(defaultEmote);
		}
	}
	dragon = loadCDragonData(emoteJson);
}

std::unordered_map<std::string, UnitInfo> Data::loadUnitData(const nlohmann::json& emoteJson, const nlohmann::json& dataJson, int set) {
	std::unordered_map<std::string, UnitInfo> infoList;
	for (auto& unit : dataJson["sets"][set]["champions"]) {
        std::string apiName = unit["apiName"].get<std::string>();
        std::string dispName = unit["name"].get<std::string>();
		int rarity = unit["cost"].get<int>() - 1;
		std::string emote;
		auto unitEmotesObj = getObj(emoteJson, "unitData");
		if (unitEmotesObj) {
			auto emoteID = getJsonStr(*unitEmotesObj, apiName);
			emote = emoteID.value_or(defaultEmote);
		} else {
			emote = defaultEmote;
		}
		infoList[apiName] = UnitInfo(dispName, rarity, emote);
    }
	return infoList;
}

std::unordered_map<std::string, TraitInfo> Data::loadTraitData(const nlohmann::json& emoteJson, const nlohmann::json& dataJson, int set) {
	std::unordered_map<std::string, TraitInfo> infoList;
	for (auto& trait : dataJson["sets"][set]["traits"]) {
		std::string apiName = trait["apiName"];
		std::string dispName = trait["name"];
		std::vector<int> traitLevels;
		std::unordered_map<int, std::string> styles;

		for (auto& level : trait["effects"]) {
			auto levelVal = getJsonInt(level, "minUnits");
			traitLevels.push_back(levelVal.value_or(0));
		}
		auto traitEmotesObj = getObj(emoteJson, "traitData");
		if (traitEmotesObj) {
			auto traitObj = getObj(*traitEmotesObj, apiName);
			if (traitObj) {
				for (auto& [innerKey, innerValue] : traitObj->items()) {
					auto emoteID = getJsonStr(*traitObj, innerKey);
					styles[std::stoi(innerKey)] = emoteID.value_or(defaultEmote);
				}
			}
		}
		infoList[apiName] = TraitInfo(dispName, traitLevels, styles);
	}
	return infoList;
}