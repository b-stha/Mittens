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

void Data::loadData() {
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
	std::unordered_map<std::string, UnitInfo> unitData = loadUnitData(dataJson, latestSet);
	std::unordered_map<std::string, TraitInfo> traitData = loadTraitData(dataJson, latestSet);

	std::cout << "Loaded data." << std::endl;
}

void Data::loadEmojis(const dpp::cluster& cluster) {
	dpp::emoji_map emojis = cluster.application_emojis_get();
}

std::unordered_map<std::string, UnitInfo> Data::loadUnitData(const nlohmann::json& dataJson, const std::string& set) {
	std::unordered_map<std::string, UnitInfo> infoList;
	for (auto& unit : dataJson["sets"][set]["champions"]) {
        std::string apiName = unit["apiName"].get<std::string>();
        std::string dispName = unit["name"].get<std::string>();
		int rarity = unit["cost"].get<int>() - 1;
		infoList[apiName] = UnitInfo(dispName, rarity);
    }
	return infoList;
}

std::unordered_map<std::string, TraitInfo> Data::loadTraitData(const nlohmann::json& dataJson, const std::string& set) {
	std::unordered_map<std::string, TraitInfo> infoList;
	for (auto& trait : dataJson["sets"][set]["traits"]) {
		std::string apiName = trait["apiName"];
		std::string dispName = trait["name"];
		std::vector<int> traitLevels;

		for (auto& level : trait["effects"]) {
			auto levelVal = getJsonInt(level, "minUnits");
			traitLevels.push_back(levelVal.value_or(0));
		}
		infoList[apiName] = TraitInfo(dispName, traitLevels);
	}
	return infoList;
}