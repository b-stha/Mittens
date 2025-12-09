#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <string>
#include <vector>
#include <dpp/dpp.h>
#include <optional>
#include <nlohmann/json.hpp>
#include <future>

struct UnitInfo{
	std::string name;
	int rarity;
};

struct TraitInfo{
	std::string name;
	std::vector<int> breakpoints;
};

class Data {
	using TraitDataMap = std::unordered_map<std::string, TraitInfo>;
	using UnitDataMap =  std::unordered_map<std::string, UnitInfo>;
public:
	const TraitDataMap& getTraitData() const { return traitData; }
	const UnitDataMap& getUnitData() const { return unitData; }
	const std::unordered_map<std::string, uint32_t>& getRankColor() const { return rankColor; }
	const std::unordered_map<int, std::string>& getPlacementData() const { return placementData; }
	const std::unordered_map<std::string, std::string>& getRankData() const { return rankRegalia; }
	const std::string& getEmote(std::string emoteName) const;
	static std::future<std::shared_ptr<Data>> asyncCreateData(dpp::cluster& cluster);

private:
	Data() = default;
	std::future<void> loadData(dpp::cluster& cluster);
	std::future<void> loadEmojis(dpp::cluster& cluster);
	std::unordered_map<std::string, UnitInfo> loadUnitData(const nlohmann::json& dataJson, const std::string& set);
	std::unordered_map<std::string, TraitInfo> loadTraitData(const nlohmann::json& dataJson, const std::string& set);
	const nlohmann::json* getObj(const nlohmann::json& j, const std::string& key) const;
	std::optional<std::string> getJsonStr(const nlohmann::json& j, const std::string& key) const;
	std::optional<int> getJsonInt(const nlohmann::json& j, const std::string& key) const;
    TraitDataMap traitData;
    UnitDataMap unitData;
	std::unordered_map<std::string, std::string> emoteMap;
	std::unordered_map<std::string, std::string> rankRegalia = {
		{"IRON", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_iron.png"},
		{"BRONZE", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_bronze.png"},
		{"SILVER", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_silver.png"},
		{"GOLD", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_gold.png"},
		{"PLATINUM", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_platinum.png"},
		{"EMERALD", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_emerald.png"},
		{"DIAMOND", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_diamond.png"},
		{"MASTER", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_master.png"},
		{"GRANDMASTER", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_grandmaster.png"},
		{"CHALLENGER", "https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_challenger.png"}};
	std::unordered_map<std::string, uint32_t> rankColor {
		{"IRON", dpp::colors::gray_brown},	
		{"BRONZE", dpp::colors::bronze},	
		{"SILVER", dpp::colors::silver},	
		{"GOLD", dpp::colors::gold},
		{"PLATINUM", dpp::colors::deep_sky_blue},	
		{"EMERALD", dpp::colors::emerald},	
		{"DIAMOND", dpp::colors::light_purple_blue},	
		{"MASTER", dpp::colors::vivid_violet},	
		{"GRANDMASTER", dpp::colors::scarlet_red},	
		{"CHALLENGER", dpp::colors::azure},	
		{"UNRANKED", dpp::colors::gray}};
	std::unordered_map<int, std::string> placementData = {
		{1,"FIRST"},
		{2,"SECOND"},
		{3,"THIRD"},
		{4,"FOURTH"},
		{5,"FIFTH"},
		{6,"SIXTH"},
		{7,"SEVENTH"},
		{8,"EIGHTH"}};
};

#endif
