#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <string>
#include <vector>
#include <dpp/dpp.h>
#include <optional>
#include <nlohmann/json.hpp>

class TraitInfo {
public:
	const std::string& getName() const { return name; };
	const std::vector<int>& getBreakpoints() const { return breakpoints; };
	TraitInfo(const std::string& name,
			  const std::vector<int>& breakpoints,
			  const std::unordered_map<int, std::string>& styles)
		: name(name), breakpoints(breakpoints) {}
	TraitInfo() = default;
private:
	std::string name;
	std::vector<int> breakpoints;
};

class UnitInfo {
public:
	const std::string& getName() const { return name; };
	int getRarity() const { return rarity; };
	UnitInfo(const std::string& name,
			 int rarity,
			 const std::string& emote)
		: name(name), rarity(rarity) {}
	UnitInfo() = default;
private:
	std::string name;
	int rarity;
};

class CDragonData{
public:
	using TraitDataMap = std::unordered_map<std::string, TraitInfo>;
	using UnitDataMap =  std::unordered_map<std::string, UnitInfo>;

	const TraitDataMap& getTraitData() const { return traitData; }
	const UnitDataMap& getUnitData() const { return unitData; }
	CDragonData(const TraitDataMap& traitDataInit,
				const UnitDataMap& unitDataInit)
		: traitData(traitDataInit), unitData(unitDataInit) {}
	CDragonData() = default;
private:
    TraitDataMap traitData;
    UnitDataMap unitData;
};

class Data {
public:
	Data() {
		loadJson();
	}
	const CDragonData& getCDragonData() const { return dragon; }
	const std::unordered_map<std::string, uint32_t>& getRankColor() const { return rankColor; }
	const std::unordered_map<int, std::string>& getPlacementData() const { return placementData; }

private:
	void loadJson();
	CDragonData loadCDragonData(const nlohmann::json& emoteJson);
	std::unordered_map<std::string, UnitInfo> loadUnitData(const nlohmann::json& emoteJson, const nlohmann::json& dataJson, const std::string& set);
	std::unordered_map<std::string, TraitInfo> loadTraitData(const nlohmann::json& emoteJson, const nlohmann::json& dataJson, const std::string& set);
	const nlohmann::json* getObj(const nlohmann::json& j, const std::string& key) const;
	std::optional<std::string> getJsonStr(const nlohmann::json& j, const std::string& key) const;
	std::optional<int> getJsonInt(const nlohmann::json& j, const std::string& key) const;
	CDragonData dragon;
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
