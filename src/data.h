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
	const std::unordered_map<int, std::string>& getStyles() const { return styles;};
	TraitInfo(const std::string& name,
			  const std::vector<int>& breakpoints,
			  const std::unordered_map<int, std::string>& styles)
		: name(name), breakpoints(breakpoints), styles(styles) {}
	TraitInfo() = default;
private:
	std::string name;
	std::vector<int> breakpoints;
	std::unordered_map<int, std::string> styles;
};

class UnitInfo {
public:
	const std::string& getName() const { return name; };
	int getRarity() const { return rarity; };
	const std::string& getEmote() const { return emote; };
	UnitInfo(const std::string& name,
			 int rarity,
			 const std::string& emote)
		: name(name), rarity(rarity), emote(emote) {}
	UnitInfo() = default;
private:
	std::string name;
	int rarity;
	std::string emote;
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
	const std::unordered_map<std::string, std::string>& getItemEmotes() const { return itemEmotes; }
	const std::unordered_map<std::string, uint32_t>& getRankColor() const { return rankColor; }
	const std::unordered_map<std::string, std::vector<std::string>>& getRankData() const { return rankEmotes; }
	const std::unordered_map<int, std::string>& getPlacementData() const { return placementData; }
	const std::string getDefaultEmote() const { return defaultEmote; }

private:
	void loadJson();
	CDragonData loadCDragonData(const nlohmann::json& emoteJson);
	std::unordered_map<std::string, UnitInfo> loadUnitData(const nlohmann::json& emoteJson, const nlohmann::json& dataJson, int set);
	std::unordered_map<std::string, TraitInfo> loadTraitData(const nlohmann::json& emoteJson, const nlohmann::json& dataJson, int set);
	const nlohmann::json* getObj(const nlohmann::json& j, const std::string& key) const;
	std::optional<std::string> getJsonStr(const nlohmann::json& j, const std::string& key) const;
	std::optional<int> getJsonInt(const nlohmann::json& j, const std::string& key) const;
	CDragonData dragon;
	std::unordered_map<std::string, std::string> itemEmotes = {
	//Item Components
	{"TFT_Item_ChainVest", "<:chain_vest:1250590480585064659>"},
	{"TFT_Item_RecurveBow", "<:recurve_bow:1251321608254001174>"},
	{"TFT_Item_BFSword", "<:bf_sword:1250590471265189930>"},
	{"TFT_Item_GiantsBelt", "<:gaints_belt:1251321470915837993>"},
	{"TFT_Item_NeedlesslyLargeRod", "<:needlessly_large_rod:1251321607549620274>"},
	{"TFT_Item_TearOfTheGoddess", "<:tear_of_the_goddess:1251321611907371121>"},
	{"TFT_Item_SparringGloves", "<:sparring_gloves:1251321609738911824>"},
	{"TFT_Item_NegatronCloak", "<:negatron_cloak:1250590511450816625>"},
	{"TFT_Item_Spatula", "<:spatula:1250590525128577095>"},
	
	//Normal Items
	{"TFT_Item_GuinsoosRageblade", "<:guinsoos_rageblade:1250590494786846771>"}, // Guinsoo's Rageblade
	{"TFT_Item_InfinityEdge", "<:infinity_edge:1250682671357497454>"}, // Infinity Edge
	{"TFT_Item_Deathblade", "<:death_blade:1250682711224614994>"}, // Deathblade
	{"TFT_Item_ThiefsGloves", "<:thieves_gloves:1250590539322101830>"}, // Thief's Gloves
	{"TFT_Item_RapidFireCannon", "<:redbuff:1250590518354772048>"}, //Red Buff
	{"TFT_Item_ArchangelsStaff", "<:archangel_staff:1250590469784731720>"}, // Archangel's Staff
	{"TFT_Item_GargoyleStoneplate", "<:gargoyle_stoneplate:1250590490718638100>"}, // Gargoyle Stoneplate
	{"TFT_Item_IonicSpark", "<:ionic_spark:1250590500461740125>"}, // Ionic Spark
	{"TFT_Item_SteraksGage", "<:steraks_gage:1251321610842144809>"}, // Sterak's Gage
	{"TFT_Item_DragonsClaw", "<:dragons_claw:1250590484527710218>"}, // Dragon's Claw
	{"TFT_Item_BrambleVest", "<:bramble_vest:1250590474859712624>"}, // Bramble Vest
	{"TFT_Item_SpearOfShojin", "<:spear_of_shojin:1251321487428817008>"}, // Spear of Shojin
	{"TFT_Item_Bloodthirster", "<:bloodthirster:1250590472754298970>"}, // Bloodthirster
	{"TFT_Item_HextechGunblade", "<:hextech_gunblade:1250590497374867518>"}, // Hextech Gunblade
	{"TFT_Item_Morellonomicon", "<:morellonomicon:1251321477270081568>"}, // Morellonomicon
	{"TFT_Item_TitansResolve", "<:titans_resolve:1251321495049732168>"}, // Titan's Resolve
	{"TFT_Item_Crownguard", "<:crownguard:1250590481285648395>"}, // Crownguard
	{"TFT_Item_AdaptiveHelm", "<:adaptive_helm:1250590468643750028>"}, // Adaptive Helm
	{"TFT_Item_BlueBuff", "<:blue_buff:1250590473828175983>"}, // Blue Buff
	{"TFT_Item_LastWhisper", "<:last_whisper:1250590503947341905>"}, // Last Whisper
	{"TFT_Item_JeweledGauntlet", "<:jeweled_guantlet:1251321475772977294>"}, // Jeweled Gauntlet
	{"TFT_Item_Quicksilver", "<:quicksilver:1251321480537571348>"}, // Quicksilver
	{"TFT_Item_WarmogsArmor", "<:warmogs_armor:1250590543017152543>"}, // Warmog's Armor
	{"TFT_Item_GuardianAngel", "<:edge_of_night:1251321469636444180>"}, //Edge of Night
	{"TFT_Item_NightHarvester", "<:behemoth:1250590470690574379>"}, //Steadfast
	{"TFT_Item_SpectralGauntlet", "<:evenshroud:1250590487325184051>"}, //Evenshroud
	{"TFT_Item_Leviathan", "<:nashors_tooth:1250590507567157352>"}, //Nashor's Tooth
	{"TFT_Item_UnstableConcoction", "<:hand_of_justice:1251321473205927997>"}, //Hand of Justice
	{"TFT_Item_PowerGauntlet", "<:stridebreaker:1250590532397301830>"}, //Stridebreaker
	{"TFT_Item_RabadonsDeathcap", "<:rabadons_deathcap:1250590514617778318>"}, // Rabadon's Deathcap
	{"TFT_Item_MadredsBloodrazor", "<:giant_slayer:1251321472350158868>"}, //Giant Slayer
	{"TFT_Item_FrozenHeart", "<:winters_approach:1251321613098553415>"}, //Protector's Vow
	{"TFT_Item_RedBuff", "<:sunfire_cape:1251321491543425116>"}, //Sunfire Cape
	{"TFT_Item_RunaansHurricane", ""}, //Kraken's Fury
	{"TFT_Item_StatikkShiv", ""}, // Void Staff
	{"TFT_Item_Redemption", ""}, // Redemption

	// Emblems
	{"TFT16_Item_BrawlerEmblemItem", ""},
	{"TFT16_Item_RapidfireEmblemItem", ""},
	{"TFT16_Item_MagusEmblemItem", ""},
	{"TFT16_Item_JuggernautEmblemItem", ""},
	{"TFT16_Item_VanquisherEmblemItem", ""},
	{"TFT16_Item_WardenEmblemItem", ""},
	{"TFT16_Item_SlayerEmblemItem", ""},
	{"TFT16_Item_GunslingerEmblemItem", ""},
	{"TFT16_Item_NoxusEmblemItem", ""},
	{"TFT16_Item_InvokerEmblemItem", ""},
	{"TFT16_Item_DefenderEmblemItem", ""},
	{"TFT16_Item_FreljordEmblemItem", ""},
	{"TFT16_Item_ZaunEmblemItem", ""},
	{"TFT16_Item_LongshotEmblemItem", ""},
	{"TFT16_Item_IoniaEmblemItem", ""},
	{"TFT16_Item_BilgewaterEmblemItem", ""},
	{"TFT16_Item_SorcererEmblemItem", ""},
	{"TFT16_Item_YordleEmblemItem", ""},
	{"TFT16_Item_PiltoverEmblemItem", ""},
	{"TFT16_Item_VoidEmblemItem", ""},
	{"TFT16_Item_DemaciaEmblemItem", ""},
	{"TFT16_Item_IxtalEmblemItem", ""},

	// Trait Items

	{"TFT16_Item_Piltover_ElectricalOverload", ""},
	{"TFT16_Item_Piltover_OverclockedCapacitors", ""},
	{"TFT16_Item_Bilgewater_PileOCitrus", ""},
	{"TFT16_Item_Bilgewater_FreebootersFrock", ""},
	{"TFT16_Item_Bilgewater_FirstMatesFlintlock", ""},
	{"TFT16_Item_Bilgewater_BilgeratCutlass", ""},
	{"TFT16_Item_Bilgewater_DeadmansDagger", ""},
	{"TFT16_Item_Bilgewater_BlackmarketExplosives", ""},
	{"TFT16_Item_Bilgewater_CaptainsBrew", ""},
	{"TFT16_Item_Bilgewater_LuckyEyepatch", ""},
	{"TFT16_Item_Piltover_AccelerationGate", ""},
	{"TFT16_Item_Piltover_BlastShield", ""},
	{"TFT16_Item_Piltover_90CaliberNets", ""},
	{"TFT16_Item_Piltover_MicroRockets", ""},
	{"TFT16_Item_Piltover_EMP", ""},
	{"TFT16_Item_Piltover_ContinuumCogs", ""},
	{"TFT16_Item_Piltover_TunedOscillator", ""},

	{"TFT_Item_TacticiansRing", "<:tacticians_ring:1290166860674760726>"},
	{"TFT_Item_TacticiansScepter", "<:tacticians_scepter:1290166861954154536>"},

	// Radiant Items
	{"TFT5_Item_WarmogsArmorRadiant", "<:warmogs_armor_radiant:1251370799835910164>"},
	{"TFT5_Item_DragonsClawRadiant", "<:dragons_claw_radiant:1251322462763876434>"},
	{"TFT5_Item_IonicSparkRadiant", "<:ionic_spark_radiant:1251322632859553913>"},
	{"TFT5_Item_QuicksilverRadiant", "<:quicksilver_radiant:1251322759473139752>"},
	{"TFT5_Item_HextechGunbladeRadiant", "<:hextech_gunblade_radiant:1251322509849006100>"},
	{"TFT5_Item_StatikkShivRadiant", ""}, // Radiant Void Staff
	{"TFT5_Item_FrozenHeartRadiant", "<:fimbulwinter_radiant:1251322466098352188>"}, //Radiant Protector's Vow
	{"TFT5_Item_BlueBuffRadiant", "<:blue_buff_radiant:1251322432867012669>"},
	{"TFT5_Item_ArchangelsStaffRadiant", "<:archangel_staff_radiant:1251322429125558353>"},
	{"TFT5_Item_MorellonomiconRadiant", "<:morellonomicon_radiant:1251322638593294346>"},
	{"TFT5_Item_BrambleVestRadiant", "<:bramble_vest_radiant:1251322433793949717>"},
	{"TFT5_Item_RunaansHurricaneRadiant", ""}, //Radiant Kraken's Fury
	{"TFT5_Item_GuinsoosRagebladeRadiant", "<:guinsoos_rageblade_radiant:1251322469181292565>"},
	{"TFT5_Item_HandOfJusticeRadiant", "<:hand_of_justice_radiant:1251322508393713874>"},
	{"TFT5_Item_SunfireCapeRadiant", "<:sunfire_cape_radiant:1251322808844161105>"},
	{"TFT5_Item_LastWhisperRadiant", "<:last_whisper_radiant:1251322635674058772>"},
	{"TFT5_Item_ThiefsGlovesRadiant", "<:thieves_gloves_radiant:1251322809918029824>"},
	{"TFT5_Item_SteraksGageRadiant", "<:steraks_gage_radiant:1251322801357328405>"},
	{"TFT5_Item_RedemptionRadiant", ""},
	{"TFT5_Item_GuardianAngelRadiant", "<:edge_of_night_radiant:1251322463787417601>"}, //Radiant Edge of Night
	{"TFT5_Item_RapidFirecannonRadiant", "<:redbuff_radiant:1251322761515634779>"}, //Radiant Red Buff
	{"TFT5_Item_NightHarvesterRadiant", "<:behemoth_radiant:1251322430618865675>"}, //Radiant Steadfast
	{"TFT5_Item_TitansResolveRadiant", "<:titans_resolve_radiant:1251322811222327296>"},
	{"TFT5_Item_GiantSlayerRadiant", "<:giant_slayer_radiant:1251322468136783934>"},
	{"TFT5_Item_CrownguardRadiant", "<:crownguard_radiant:1251322436801003571>"},
	{"TFT5_Item_BloodthirsterRadiant", "<:bloodthirster_radiant:1251322431881216031>"},
	{"TFT5_Item_RabadonsDeathcapRadiant", "<:rabadons_deathcap_radiant:1251322760127582341>"},
	{"TFT5_Item_JeweledGauntletRadiant", "<:jeweled_gauntlet_radiant:1251322633996210226>"},
	{"TFT5_Item_GargoyleStoneplateRadiant", "<:gargoyle_stoneplate_radiant:1251322467042197525>"},
	{"TFT5_Item_LeviathanRadiant", "<:nashors_tooth_radiant:1251322758223368213>"}, //Radiant Nashor's Tooth
	{"TFT5_Item_SpearOfShojinRadiant", "<:spear_of_shojin_radiant:1251322766645395477>"},
	{"TFT5_Item_InfinityEdgeRadiant", "<:infinity_edge_radiant:1251322631639273542>"},
	{"TFT5_Item_AdaptiveHelmRadiant", "<:adaptive_helm_radiant:1251322428131508375>"},
	{"TFT5_Item_DeathbladeRadiant", "<:death_blade_radiant:1251322461128097875>"},
	{"TFT5_Item_SpectralGauntletRadiant", "<:evenshroud_radiant:1251322464492064769>"}, //Radiant Evenshroud
	{"TFT5_Item_TrapClawRadiant", "<:stridebreakerradiant:1251322807690989598>"}, //Radiant Guardbreaker

	//Ornn Artifacts
	{"TFT_Item_Artifact_AegisOfDawn", "" }, // Aegis of Dawn 
	{"TFT_Item_Artifact_AegisOfDusk", ""}, // Aegis of Dusk
	{"TFT_Item_Artifact_CappaJuice", ""}, // Cappa Juice
	{"TFT_Item_Artifact_EternalPact", ""}, // Eternal Pact
	{"TFT_Item_Artifact_HellfireHatchet", ""}, // Hellfire Hatchet
	{"TFT_Item_Artifact_LudensTempest", ""}, // Luden's Tempest
	{"TFT_Item_Artifact_ShadowPuppet", ""}, // Shadow Puppet
	{"TFT16_TheDarkinAegis", ""}, // The Darkin Aegis
	{"TFT16_TheDarkinBow", ""}, // The Darkin Bow
	{"TFT16_TheDarkinScythe", ""}, // The Darkin Scythe
	{"TFT16_TheDarkinStaff", ""}, // The Darkin Staff
	{"TFT_Item_Artifact_VoidGauntlet", ""}, // Void Gauntlet
	{"TFT_Item_Artifact_Dawncore", ""}, // Dawncore
	{"TFT_Item_Artifact_StatikkShiv", ""}, // Statikk Shiv
	{"TFT_Item_Artifact_TheIndomitable", ""}, // The Indomitable
	{"TFT_Item_Artifact_TitanicHydra", ""}, // Titanic Hydra
	{"TFT_Item_Artifact_NavoriFlickerblades", ""}, // Flickerblades
	{"TFT7_Item_ShimmerscaleMogulsMail", ""}, // Mogul's Mail
	{"TFT4_Item_OrnnMuramana", "<:tft4_ornnitem_marksman_t3_murama:1251323059248431176>"},  // Manazane
	{"TFT9_Item_OrnnTrickstersGlass", "<:tft9_ornnitem_trickstersglass:1251323219580031057>"}, // Trickster's Glass
	{"TFT4_Item_OrnnInfinityForce", "<:tft4_ornnitem_fighter_t4_trinity:1251323027875041410>"}, // Infinity Force
	{"TFT4_Item_OrnnDeathsDefiance", "<:tft4_ornnitem_fighter_t3_deathsd:1251322998477291630>"}, // Death's Defiance
	{"TFT9_Item_OrnnHorizonFocus", "<:tft9_ornnitem_snipersfocus:1251323218313085028>"}, // Sniper's Focus
	{"TFT_Item_Artifact_SpectralCutlass", "<:tft_item_artifact_spectralcutlas:1251322992550740038>"}, // Spectral Cutlass
	{"TFT4_Item_OrnnZhonyasParadox", "<:tft4_ornnitem_mage_t3_zhonyashou:1251323056689905755>"}, // Zhonya's Paradox
	{"TFT9_Item_OrnnHullbreaker", "<:tft9_ornnitem_hullbreaker:1251323215771599001>"}, // Hullbreaker
	{"TFT_Item_Artifact_LightshieldCrest", "<:tft_item_artifact_lightshieldcre:1251322966961295391>"}, // Lightshield Crest
	{"TFT_Item_Artifact_BlightingJewel", "<:tft_item_artifact_blightingjewel:1251322940830650439>"}, // Blighting Jewel
	{"TFT_Item_Artifact_TalismanOfAscension", "<:tft_item_artifact_talismanofasce:1251322994744229929>"}, // Talisman of Ascension
	{"TFT_Item_Artifact_RapidFirecannon", "<:tft_item_artifact_rapidfirecanno:1251322972611022869>"}, // Rapid Firecannon
	{"TFT_Item_Artifact_Mittens", "<:tft_item_artifact_mittens:1251322970010550354>"}, // Mittens
	{"TFT9_Item_OrnnDeathfireGrasp", "<:tft9_ornnitem_deathfiregrasp:1251323214680952922>"}, // Deathfire Grasp
	{"TFT_Item_Artifact_WitsEnd", "<:tft_item_artifact_witsend:1251322996799307818>"}, // Wit's End
	{"TFT_Item_Artifact_ProwlersClaw", "<:tft_item_artifact_prowlersclaw:1251322971587477534>"}, // Prowler's Claw
	{"TFT_Item_Artifact_SilvermereDawn", "<:tft_item_artifact_silvermeredawn:1251322991229276222>"}, // Silvermere Dawn
	{"TFT_Item_Artifact_SeekersArmguard", "<:tft_item_artifact_seekersarmguar:1251322973428777012>"}, // Seeker's Armguard
	{"TFT_Item_Artifact_Fishbones", "<:tft_item_artifact_fishbones:1251322943804280975>"}, // Fishbones
	{"TFT7_Item_ShimmerscaleGamblersBlade_HR", "<:tft10_gamblersblade:1251323222499262504>"}, // Gambler's Blade
	{"TFT4_Item_OrnnTheCollector", "<:tft4_ornnitem_marksman_t3_thecol:1251323109840257056>"}, // Gold Collector
	{"TFT_Item_Artifact_InnervatingLocket", "<:tft_item_artifact_innervatingloc:1251322964658487408>"}, // Innervating Locket
	{"TFT_Item_Artifact_LichBane", "<:tft_item_artifact_lichbane:1251322965987950644>"}, // Lich Bane
	{"TFT_Item_Artifact_HorizonFocus", "<:tft_item_artifact_horizonfocus:1251322946337902653>"}, // Horizon Focus
	{"TFT_Item_Artifact_UnendingDespair", "<:tft_item_artifact_unendingdespai:1251322995851526185>"}, // Unending Despair

	//Support Items
	{"TFT5_Item_ZzRotPortalRadiant", "<:zzrot_portal:1251374701226229830>"},
	{"TFT_Item_Moonstone", "<:moonstone:1251374277383421973>"},
	{"TFT4_Item_OrnnObsidianCleaver", "<:obsidian_cleaver:1251374383591854141>"},
	{"TFT_Item_RadiantVirtue", "<:radiant_virtue:1251374384791425024>"},
	{"TFT_Item_AegisOfTheLegion", "<:aegis:1251374228658196612>"},
	{"TFT_Item_ZekesHerald", "<:zekes_herald:1251374440793509980>"},
	{"TFT_Item_BansheesVeil", "<:banshees_veil:1251374230352957562>"},
	{"TFT_Item_Chalice", "<:chalice_of_power:1251374231749394473>"},
	{"TFT_Item_EternalFlame", "<:eternal_flame:1251374232739516598>"},
	{"TFT_Item_LocketOfTheIronSolari", "<:locket_of_the_iron_solari:1251374276163141632>"},
	{"TFT4_Item_OrnnRanduinsSanctum", "<:randuins_sanctum_support:1251374386284597279>"},
	{"TFT_Item_SupportKnightsVow", "<:knights_vow:1251374274996998164>"},
	{"TFT_Item_Shroud", "<:shroud_of_stillness:1251374396363509851>"},
	{"TFT11_Item_ThiefsGlovesSupport", "<:thieves_gloves:1250590539322101830>"},
	{"TFT_Item_Spite", "<:spite:1251374397546168330>"},
	{"TFT7_Item_ShimmerscaleHeartOfGold", "<:needlessy_large_gem:1251374324582187048>"},
	{"TFT_Item_UnstableTreasureChest", "<:unstable_treasure_chest:1251374398493954203>"},
	{"TFT_Item_Zephyr", "<:zephyr:1251374441972109322>"},
};
	std::unordered_map<std::string, std::vector<std::string>> augmentEmotes = {
	{"TFT11_Augment_GoldenRemover", {"The Golden Remover","<:goldenremover_i:1251762777358336021>"}},
	{"TFT_Augment_GoldenQuest", {"A Golden Quest",""}},
	{"TFT7_Augment_AFK", {"AFK",""}},
	{"TFT12_Augment_Preserver", {"Aggressive Perseverance",""}},
	{"TFT9_Augment_AllThatShimmers", {"All That Shimmers",""}},
	{"TFT_Augment_AllThatShimmersPlus", {"All That Shimmers+",""}},
	{"TFT_Augment_AnUpgradedJourney", {"An Upgraded Adventure",""}},
	{"TFT_Augment_OopsAllRageblades", {"Anger Issues",""}},
	{"TFT12_Augment_ArcanaCrest", {"Arcana Crest",""}},
	{"TFT12_Augment_ArcanaCrown", {"Arcana Crown",""}},
	{"TFT12_Augment_Arcana", {"Arcane Conduit",""}},
	{"TFT9_Augment_Commander_Ascension", {"Ascension","<:ascension2:1251323391739170919>"}},
	{"TFT_Augment_AssassinsToolbox", {"Assassin's Toolbox",""}},
	{"TFT11_Augment_AtWhatCost", {"At What Cost",""}},
	{"TFT_Augment_AvengeTheFallen", {"Avenge The Fallen",""}},
	{"TFT9_Augment_BalancedBudget2", {"Balanced Budget","<:balancedbudgetii:1251323396105699348>"}},
	{"TFT9_Augment_BalancedBudgetPlus", {"Balanced Budget+","<:balancedbudgetii:1251323396105699348>"}},
	{"TFT7_Augment_BandOfThieves1", {"Band of Thieves I","<:bandthieves1:1251323397443551304>"}},
	{"TFT12_Augment_BastionCrest", {"Bastion Crest",""}},
	{"TFT12_Augment_BastionCrown", {"Bastion Crown",""}},
	{"TFT12_Augment_Honeymancy", {"Bee-st Friends",""}},
	{"TFT_Augment_BeggarsCanBeChoosers", {"Beggars Can Be Choosers",""}},
	{"TFT10_Augment_BigGains", {"Big Gains","<:biggainsii:1251323452842053662>"}},
	{"TFT9_Augment_BigGrabBag", {"Big Grab Bag","<:grabbagii:1251347707856031804>"}},
	{"TFT7_Augment_BirthdayPresents", {"Birthday Present","<:goldengiftsiii:1251347582387622081>"}},
    {"TFT12_Augment_BlasterCrest", {"Blaster Crest", ""}},
    {"TFT12_Augment_BlasterCrown", {"Blaster Crown", ""}},
	{"TFT9_Augment_BlindingSpeed", {"Blinding Speed","<:berserkiii:1251323433023701064>"}},
	{"TFT9_Augment_RedBuff", {"Blistering Strikes","<:redbuffi:1251348646994382888>"}},
	{"TFT_Augment_BlossomingLotus1", {"Blossoming Lotus I",""}},
	{"TFT_Augment_BlossomingLotus2", {"Blossoming Lotus II",""}},
	{"TFT_Augment_BranchingOut", {"Branching Out","<:branchingouti:1251323455899697213>"}},
	{"TFT11_Augment_Buildabud", {"Build a Bud!","<:buildabud_iii:1251323457434812436>"}},
	{"TFT6_Augment_Traitless2", {"Built Different II","<:builtdifferent2:1251323460232282112>"}},
	{"TFT9_Augment_BuildingACollectionPlusPlus", {"Buried Treasures III","<:buriedtreasuresiii:1251324876707332167>"}},
	{"TFT_Augment_CalledShot", {"Called Shot",""}},
	{"TFT11_Augment_Calltochaos", {"Call to Chaos","<:calltochaos_iii:1251324879630897173>"}},
	{"TFT9_Augment_CapriciousForge", {"Capricious Forge","<:prototypeforgeii:1251348596742164511>"}},
	{"TFT12_Augment_Sugarcraft", {"Caramelized Comforts",""}},
	{"TFT9_Augment_BardPlaybook1", {"Caretaker's Ally","<:caretaker_schoseni:1251324881124065381>"}},
	{"TFT9_Augment_BardPlaybook3", {"Caretaker's Chosen","<:caretaker_schoseniii:1251324882617237644>"}},
	{"TFT9_Augment_BardPlaybook2", {"Caretaker's Favor","<:caretaker_schosenii:1251761972802748479> "}},
	{"TFT_Augment_CategoryFive", {"Category Five",""}},
	{"TFT12_Augment_Pyro", {"Cauterize",""}},
	{"TFT12_Augment_ChronoCrest", {"Chrono Crest",""}},
	{"TFT12_Augment_ChronoCrown", {"Chrono Crown",""}},
	{"TFT6_Augment_ClearMind", {"Clear Mind","<:clearmind2:1251324884085375047>"}},
	{"TFT_Augment_ClockworkAccelerator", {"Clockwork Accelerator",""}},
	{"TFT7_Augment_ClutteredMind", {"Cluttered Mind","<:dizzyii:1251347464871477438>"}},
	{"TFT_Augment_DawnbringersBlessing1", {"Combat Bandages I",""}},
	{"TFT_Augment_DawnbringersBlessing2", {"Combat Bandages II",""}},
	{"TFT9_Augment_CombatCaster", {"Combat Caster","<:combatcasterii:1251324885444329645>"}},
	{"TFT9_Augment_CustomerIsAlwaysRight", {"Component Buffet","<:thecustomerisalwaysrighti:1251377626564788265>"}},
	{"TFT10_Augment_CrashTestDummies", {"Crash Test Dummies","<:crashtestdummiesii:1251324994643038321>"}},
	{"TFT10_Augment_CrownGuarded", {"Crown Guarded","<:crownguardedii:1251347320235360367>"}},
	{"TFT_Augment_DarkAlleyDealings", {"Dark Alley Dealings",""}},
	{"TFT12_Augment_Incantor", {"Defensive Arts",""}},
	{"TFT12_Augment_GalioCarry", {"Deja Vu",""}},
	{"TFT12_Augment_GalioCarryPlus", {"Deja Vu+",""}},
	{"TFT_Augment_DoubleDown", {"Double Down",""}},
	{"TFT12_Augment_Dragon", {"Draconic Mastery",""}},
	{"TFT11_Augment_DragonSpirit", {"Dragon's Spirit","<:dragonsspirit_ii:1251347466037755904>"}},
	{"TFT_Augment_DualPurpose", {"Dual Purpose",""}},
	{"TFT_Augment_DuoQueue", {"Duo Queue",""}},
	{"TFT12_Augment_EldritchCrest", {"Eldritch Crest",""}},
	{"TFT12_Augment_EldritchCrown", {"Eldritch Crown",""}},
	{"TFT11_Augment_Epoch", {"Epoch","<:epoch_ii:1251347507351654510>"}},
	{"TFT11_Augment_EpochPlus", {"Epoch+","<:epoch_ii:1251347507351654510>"}},
	{"TFT9_Augment_EscortQuest", {"Escort Quest","<:escortquestii:1251347508349632552>"}},
	{"TFT12_Augment_Shapeshifter", {"Eternal Growth",""}},
	{"TFT12_Augment_ShapeshifterPlus", {"Eternal Growth+",""}},
	{"TFT6_Augment_Distancing", {"Exiles I","<:exiles1:1251347510648373301>"}},
	{"TFT_Augment_ExplosiveGrowth", {"Explosive Growth",""}},
	{"TFT_Augment_ExplosiveGrowthPlus", {"Explosive Growth+",""}},
	{"TFT12_Augment_FaerieCrest", {"Faerie Crest",""}},
	{"TFT12_Augment_FaerieCrown", {"Faerie Crown",""}},
	{"TFT12_Augment_Chrono", {"Fast Forward",""}},
	{"TFT6_Augment_Featherweights1", {"Featherweights I","<:featherweights1:1251347512166715433>"}},
	{"TFT9_Augment_Commander_FinalAscension", {"Final Ascension","<:ascension3:1251323393291063398>"}},
	{"TFT_Augment_FinalResistance", {"Final Resistance",""}},
	{"TFT_Augment_FindYourCenter", {"Find Your Center",""}},
	{"TFT11_Augment_FineVintage", {"Fine Vintage","<:finevintage_i:1251347513370345592>"}},
	{"TFT_Augment_Flexible", {"Flexible",""}},
	{"TFT_Augment_FortuneFavorsTheBold", {"Fortune Favors the Bold",""}},
	{"TFT12_Augment_FrostCrest", {"Frost Crest",""}},
	{"TFT12_Augment_FrostCrown", {"Frost Crown",""}},
	{"TFT12_Augment_Frost", {"Frosty Frontline",""}},
	{"TFT_Augment_GiantAndMighty", {"Giant and Mighty",""}},
	{"TFT10_Augment_GoingLong", {"Going Long","<:goinglongiii:1251347579602735124>"}},
	{"TFT10_Augment_GoodForSomethingSilver", {"Good For Something I","<:goodforsomethingi:1251347607742054531>"}},
    {"TFT_Augment_HardCommit", {"Hard Commit", ""}},
	{"TFT9_Augment_HedgeFund", {"Hedge Fund","<:richgetricher3:1251348651742199880>"}},
	{"TFT10_Augment_HelpIsOnTheWay", {"Help Is On The Way","<:helpisonthewayi:1251347783227670559>"}},
	{"TFT10_Augment_HeroicGrabBag", {"Heroic Grab Bag","<:heroicgrabbagii:1251347784578236518>"}},
    {"TFT12_Augment_LilliaCarry", {"High Horsepower", ""}},
    {"TFT_Augment_HighVoltage", {"High Voltage", ""}},
    {"TFT12_Augment_Scholar", {"Higher Education", ""}},
    {"TFT12_Augment_HoneymancyCrest", {"Honeymancy Crest", ""}},
    {"TFT12_Augment_HoneymancyCrown", {"Honeymancy Crown", ""}},
    {"TFT12_Augment_HunterCrest", {"Hunter Crest", ""}},
    {"TFT12_Augment_HunterCrown", {"Hunter Crown", ""}},
    {"TFT12_Augment_Hunter", {"Hunting Frenzy", ""}},
    {"TFT_Augment_ImTheCarryNow", {"I'm The Carry Now", ""}},
    {"TFT_Augment_RanduinsImmovableObject", {"Immovable Object", ""}},
	{"TFT9_Augment_ImpenetrableBulwark", {"Impenetrable Bulwark","<:standbehind3:1251377587289194588>"}},
    {"TFT12_Augment_IncantorCrest", {"Incantor Crest", ""}},
    {"TFT12_Augment_IncantorCrown", {"Incantor Crown", ""}},
	{"TFT10_Augment_InspiringEpitaph", {"Inspiring Epitaph","<:inspiringepitaphii:1251347786964795445>"}},
    {"TFT_Augment_InvestedPlus", {"Invested+", ""}},
    {"TFT_Augment_InvestedPlusPlus", {"Invested++", ""}},
	{"TFT9_Augment_IronAssets", {"Iron Assets","<:ironassetsi:1251347818862612561>"}},
    {"TFT_Augment_ItemCollector1", {"Item Collector I", ""}},
    {"TFT_Augment_ItemCollector2", {"Item Collector II", ""}},
	{"TFT6_Augment_ItemGrabBag1", {"Item Grab Bag I", "<:itemgrabbag1:1251347819969642516>"}},
    {"TFT_Augment_ItemLadder", {"Item Ladder", ""}},
	{"TFT6_Augment_Keepers1", {"Keepers I", "<:keepersi:1251347826471075930>"}},
	{"TFT6_Augment_Keepers2", {"Keepers II", "<:keepersii:1251347828333346828>"}},
	{"TFT7_Augment_LategameSpecialist", {"Lategame Specialist", "<:lategamespecialisti:1251347831042740344>"}},
	{"TFT9_Augment_LongTimeCrafting", {"Latent Forge", "<:longtimecraftingi:1251348133984735304>"}},
	{"TFT10_Augment_LearningToSpell", {"Learning to Spell", "<:learningtospellii:1251347895857315931>"}},
	{"TFT6_Augment_MaxLevel10", {"Level Up!", "<:levelup3:1251347897568460862>"}},
	{"TFT10_Augment_LittleBuddies", {"Little Buddies", "<:littlebuddiesii:1251347899766538312>"}},
	{"TFT7_Augment_LivingForge", {"Living Forge", "<:livingforgeiii:1251348096982716551>"}},
	{"TFT9_Augment_LongDistanceRelationship2", {"Long Distance Pals", "<:longdistancerelationshipii:1251348098723217470>"}},
	{"TFT7_Augment_LuckyGloves", {"Lucky Gloves", "<:luckyglovesiii:1251348137650688122>"}},
	{"TFT7_Augment_LuckyGlovesPlus", {"Lucky Gloves+", "<:luckyglovesiii:1251348137650688122>"}},
	{"TFT11_Augment_BloodBank", {"Lunch Money", "<:bloodbank_i:1251323453873586217>"}},
    {"TFT12_Augment_MageCrest", {"Mage Crest", ""}},
    {"TFT12_Augment_MageCrown", {"Mage Crown", ""}},
	{"TFT9_Augment_OldMansWalkingStick", {"Magic Wand", "<:oldman_swalkingstickii:1251348220718878770>"}},
	{"TFT6_Augment_SlowAndSteady", {"March of Progress", "<:slowandsteady3:1251377584877604907>"}},
    {"TFT_Augment_MarksmansToolbox", {"Marksman's Toolbox", ""}},
	{"TFT9_Augment_Martyr", {"Martyr", "<:martyrii:1251348143715389561>"}},
    {"TFT_Augment_Mentorship1", {"Mentorship I", ""}},
    {"TFT_Augment_Mentorship2", {"Mentorship II", ""}},
	{"TFT6_Augment_MetabolicAccelerator", {"Metabolic Accelerator", "<:metabolicaccel2:1251348213265334313>"}},
	{"TFT9_Augment_MissedConnections", {"Missed Connections", "<:missedconnectionsi:1251348215484387429>"}},
    {"TFT12_Augment_RumbleCarry", {"Molten Caramel", ""}},
    {"TFT12_Augment_RumbleCarryPlus", {"Molten Caramel+", ""}},
    {"TFT12_Augment_HunterCrest", {"Multistriker Crest", ""}},
    {"TFT12_Augment_MultistrikerCrown", {"Multistriker Crown", ""}},
	{"TFT6_Augment_ForceOfNature", {"New Recruit", "<:newrecruit3:1251348218470600704>"}},
	{"TFT9_Augment_NotToday", {"Not Today", "<:nottodayii:1251348219728887839>"}},
    {"TFT_Augment_OnTheHouse", {"On The House", ""}},
	{"TFT6_Augment_OneTwoFive", {"One, Two,Five!", "<:onetwofivei:1251348221339369543>"}},
	{"TFT9_Augment_OneTwosThree", {"Ones Twos Three", "<:threescompanyi:1251377670563041291>"}},
	{"TFT11_Augment_OverEncumbered", {"Over Encumbered", "<:overencumbered_i:1251348505084039199>"}},
	{"TFT6_Augment_PandorasItems", {"Pandora's Items", "<:pandora1:1251348506212434011>"}},
	{"TFT9_Augment_PandorasItems2", {"Pandora's Items II", "<:pandora2:1251348507210678302>"}},
	{"TFT9_Augment_PandorasRadiantBox", {"Pandora's Items III", "<:pandora3:1251348508238418012>"}},
	{"TFT9_Augment_Commander_PartialAscension", {"Partial Ascension", "<:ascension1:1251323390556635220>"}},
    {"TFT_Augment_PatienceIsAVirtue", {"Patience is a Virtue", ""}},
	{"TFT9_Augment_LearningFromExperience2", {"Patient Study", "<:learningfromexperienceii:1251347894485782569>"}},
	{"TFT9_Augment_PhreakyFriday", {"Phreaky Friday", "<:phreakyfridayiii:1251348509479927808>"}},
	{"TFT9_Augment_PhreakyFridayPlus", {"Phreaky Friday+", "<:phreakyfridayiii:1251348509479927808>"}},
    {"TFT_Augment_Pilfer", {"Pilfer", ""}},
    {"TFT_Augment_Placebo", {"Placebo", ""}},
    {"TFT_Augment_PlaceboPlus", {"Placebo", ""}},
	{"TFT6_Augment_PortableForge", {"Portable Forge", "<:portableforge2:1251348512415944755>"}},
    {"TFT12_Augment_PortalCrest", {"Portal Crest", ""}},
    {"TFT12_Augment_PortalCrown", {"Portal Crown", ""}},
    {"TFT12_Augment_Portal", {"Portal Delivery Service", ""}},
    {"TFT12_Augment_Witch", {"Potions 201", ""}},
    {"TFT12_Augment_Mage", {"Practice Partners", ""}},
    {"TFT_Augment_PerfectLoss", {"Precise Planning", ""}},
    {"TFT12_Augment_PreserverCrest", {"Preserver Crest", ""}},
    {"TFT12_Augment_PreserverCrown", {"Preserver Crown", ""}},
    {"TFT12_Augment_Multistriker", {"Press The Attack", ""}},
	{"TFT6_Augment_GachaAddict", {"Prismatic Ticket", "<:goldenticket3:1251347584774045726>"}},
	{"TFT11_Augment_Prizefighter", {"Prizefighter", "<:prizefighter_ii:1251348513581957154>"}},
	{"TFT9_Augment_PumpingUp", {"Pumping Up I", "<:pumpingupi:1251348597967163473>"}},
	{"TFT9_Augment_PumpingUp2", {"Pumping Up II", "<:pumpingupii:1251348599183249428>"}},
	{"TFT9_Augment_PumpingUp3", {"Pumping Up III", "<:pumpingupiii:1251348600605376623>"}},
    {"TFT12_Augment_PyroCrest", {"Pyro Crest", ""}},
    {"TFT12_Augment_PyroCrown", {"Pyro Crown", ""}},
	{"TFT11_Augment_RadiantRefactor", {"Radiant Refactor", "<:radiantrefactor_iii:1251348601649627263>"}},
	{"TFT6_Augment_RadiantRelics", {"Radiant Relics", "<:radiantreliciii:1251348602757058682>"}},
	{"TFT12_Augment_Bastion", {"Raid Boss", "<:raidboss_ii:1251348604015087627>"}},
	{"TFT11_Augment_RainingGold", {"Raining Gold", "<:raininggold_ii:1251348605390815272>"}},
	{"TFT11_Augment_RainingGoldPlus", {"Raining Gold+", "<:raininggold_ii:1251348605390815272>"}},
	{"TFT6_Augment_Recombobulator", {"Recombobulator", "<:recombobulatori:1251348645651943506>"}},
	{"TFT11_Augment_Reinfourcement", {"ReinFOURcement", "<:reinfourcement_ii:1251348650295296110>"}},
    {"TFT_Augment_Replication", {"Replication", ""}},
    {"TFT_Augment_RestartMission", {"Restart Mission", ""}},
	{"TFT9_Augment_RiskyMoves", {"Risky Moves", "<:riskymovesi:1251348652945969265>"}},
	{"TFT9_Augment_RollTheDice", {"Roll The Dice", "<:rollingfordaysi:1251348653789155369>"}},
	{"TFT9_Augment_Commander_RollingForDays", {"Rolling For Days I", "<:rollthediceiii:1251348689700782130>"}},
    {"TFT_Augment_ReinforcedRejuvenation1", {"Row Rejuvenation I", ""}},
    {"TFT_Augment_ReinforcedRejuvenation2", {"Row Rejuvenation II", ""}},
    {"TFT12_Augment_Faerie", {"Royal Guard", ""}},
	{"TFT10_Augment_Scapegoat", {"Scapegoat", "<:thescapegoatii:1251377667144417310>"}},
    {"TFT12_Augment_ScholarCrest", {"Scholar Crest", ""}},
    {"TFT12_Augment_ScholarCrown", {"Scholar Crown", ""}},
    {"TFT12_Augment_Eldritch", {"School Mascot", ""}},
	{"TFT11_Augment_ScoreboardScrapper", {"Scoreboard Scrapper", "<:scoreboardscrapper_ii:1251348691898597497>"}},
    {"TFT12_Augment_ShapeshifterCrest", {"Shapeshifter Crest", ""}},
    {"TFT12_Augment_ShapeshifterCrown", {"Shapeshifter Crown", ""}},
    {"TFT12_Augment_Vanguard", {"Shields Up", ""}},
    {"TFT_Augment_ShimmerscaleEssence", {"Shimmerscale Essence", ""}},
	{"TFT9_Augment_SilverSpoon", {"Silver Spoon", "<:silverspooni:1251348695568351243>"}},
	{"TFT9_Augment_BronzeTicket", {"Silver Ticket", "<:goldenticket1:1251347583494914088>"}},
	{"TFT10_Augment_SilverVeil", {"Silver Veil", "<:thesilverveili:1251377668390391808>"}},
	{"TFT11_Augment_Slammin", {"Slammin'", "<:slammin_ii:1251348697313447966>"}},
	{"TFT11_Augment_Slammin_Plus", {"Slammin'+", "<:slammin_ii:1251348697313447966>"}},
	{"TFT9_Augment_Sleightofhand", {"Sleight of Hand", "<:sleightofhandii:1251377556263796859>"}},
    {"TFT_Augment_Spellblades", {"Spellblades", ""}},
    {"TFT_Augment_SpellcastersToolbox", {"Spellcaster's Toolbox", ""}},
    {"TFT12_Augment_EliseCarry", {"Spider Queen", ""}},
    {"TFT12_Augment_WukongCarry", {"Spin to Win", ""}},
    {"TFT9_Augment_DravenSpoilsOfWar", {"Spoils of War I", ""}},
    {"TFT9_Augment_DravenSpoilsOfWar2", {"Spoils of War II", ""}},
    {"TFT9_Augment_DravenSpoilsOfWar3", {"Spoils of War III", ""}},
	{"TFT6_Augment_Diversify2", {"Stand United II", "<:standunited2:1251377588698484806>"}},
	{"TFT9_Augment_StarsAreBorn", {"Stars are Born", "<:starsarebornii:1251377590049177701>"}},
	{"TFT9_Augment_StationarySupport1HR", {"Stationary Support I", "<:stationarysupporti:1251377592397860894>"}},
	{"TFT10_Augment_Stimpack", {"Stimpack", "<:stimpacki:1251377618620645386>"}},
    {"TFT_Augment_SubscriptionService", {"Subscription Service", ""}},
    {"TFT12_Augment_SugarcraftCrest", {"Sugarcraft Crest", ""}},
    {"TFT12_Augment_SugarcraftCrown", {"Sugarcraft Crown", ""}},
	{"TFT9_Augment_SupportCache", {"Support Cache", "<:supportcacheii:1251377621028175922>"}},
    {"TFT_Augment_SupportSentinel", {"Support Golem I", ""}},
    {"TFT_Augment_SupportSentinel2", {"Support Golem II", ""}},
    {"TFT12_Augment_NunuCarry", {"Sweet Tooth", ""}},
    {"TFT12_Augment_NunuCarryPlus", {"Sweet Tooth+", ""}},
	{"TFT9_Augment_ArmyBuilding", {"Team Building", "<:buildinganarmyi:1251323459028521030>"}},
	{"TFT9_Augment_Commander_TeamingUp1", {"Teaming Up I", "<:teamingupi:1251377623758540882>"}},
	{"TFT9_Augment_Commander_TeamingUp2", {"Teaming Up II", "<:teamingupii:1251377625398644827>"}},
	{"TFT6_Augment_TheGoldenEgg", {"The Golden Egg", "<:thegoldeneggiii:1251377664204472330>"}},
    {"TFT_Augment_ThornPlatedArmor", {"Thorn-Plated Armor", ""}},
	{"TFT6_Augment_ThreesCompany", {"Three's Company", "<:threescompanyii:1251377672261730314>"}},
	{"TFT9_Augment_ThreesACrowd", {"Three's a Crowd", "<:three_sacrowdii:1251377669778571394>"}},
	{"TFT9_Augment_TiniestTitan", {"Tiniest Titan", "<:tiniesttitaniii:1251377673599455305>"}},
	{"TFT9_Augment_TiniestTitanPlus", {"Tiniest Titan+", "<:tiniesttitaniii:1251377673599455305>"}},
	{"TFT6_Augment_TinyTitans", {"Tiny Titans", "<:tinytitansi:1251377709725253693>"}},
	{"TFT11_Augment_TinyButDeadly", {"Tiny, but Deadly", "<:tinybutdeadly_iii:1251377708324225096>"}},
	{"TFT6_Augment_TradeSector", {"Trade Sector", "<:trade2:1251377713873293332>"}},
    {"TFT_Augment_TraitTracker", {"Trait Tracker", ""}},
    {"TFT12_Augment_Transfiguration", {"Transfiguration", ""}},
	{"TFT6_Augment_TriForce1", {"Tri Force I", "<:triforcei:1251377715798343711>"}},
	{"TFT9_Augment_TwoHealthy", {"Two Healthy", "<:twohealthyii:1251377759863705642>"}},
    {"FT_Augment_TwoTanky", {"Two Tanky", ""}},
	{"TFT9_Augment_Formation1", {"Unified Resistance I", "<:redroveri:1251348648076251176>"}},
	{"TFT9_Augment_Formation2", {"Unified Resistance II", "<:redroverii:1251348649146056795>"}},
    {"TFT_Augment_UnleashTheBeast", {"Unleash The Beast", ""}},
    {"TFT_Augment_UpwardMobility", {"Upward Mobility", ""}},
    {"TFT12_Augment_VanguardCrest", {"Vanguard Crest", ""}},
    {"TFT12_Augment_VanguardCrown", {"Vanguard Crown", ""}},
    {"TFT_Augment_VerticallyInclined", {"Vertically Inclined", ""}},
	{"TFT11_Augment_WanderingTrainerGold", {"Wandering Trainer I", "<:wanderingtrainerii:1251377762157989908>"}},
	{"TFT9_Augment_WanderingTrainer", {"Wandering Trainer II", "<:wanderingtraineriii:1251377763642769468>"}},
    {"TFT12_Augment_WarriorCrest", {"Warrior Crest", ""}},
    {"TFT12_Augment_WarriorCrown", {"Warrior Crown", ""}},
	{"TFT9_Augment_WhatDoesntKillYou", {"What Doesn't Kill You", "<:whatdoesn_tkillyouii:1251377766147031064>"}},
    {"TFT9_Augment_WhatDoesntKillYou", {"What Doesn't Kill You", ""}},
    {"TFT9_Augment_WhatTheForge", {"What the Forge", ""}},
    {"TFT12_Augment_WitchcraftCrest", {"Witchcraft Crest", ""}},
    {"TFT12_Augment_WitchcraftCrown", {"Witchcraft Crown", ""}},
    {"TFT12_Augment_PoppyCarry", {"Witchy Wallop", ""}},
    {"TFT_Augment_WorthTheWaitGold", {"Worth the Wait", ""}},
    {"TFT_Augment_WorthTheWaitPrismatic", {"Worth the Wait II", ""}},
	{"TFT9_Augment_YouHaveMyBow", {"You Have My Bow", "<:youhavemybowii:1251377769074528276>"}},
	{"TFT9_Augment_YouHaveMySword", {"You Have My Sword", "<:youhavemyswordii:1251377794340880485>"}},
	{"TFT9_Augment_YoungAndWildAndFree", {"Young and Wild and Free", "<:youngandwildandfreei:1251377795485925416>"}},
    {"TFT12_Augment_BlitzcrankCarry", {"Zap Attack", ""}},
};
	std::unordered_map<std::string, std::vector<std::string>> rankEmotes = {
	{"IRON", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_iron.png", "<:iron_tft:1310873413807771668>"}},
	{"BRONZE", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_bronze.png", "<:bronze_tft:1310873405888794654>"}},
	{"SILVER", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_silver.png", "<:silver_tft:1310873462780329994>"}},
	{"GOLD", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_gold.png", "<:gold_tft:1310873410804514826>"}},
	{"PLATINUM", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_platinum.png", "<:platinum_tft:1310873418182168617>"}},
	{"EMERALD", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_emerald.png", "<:emerald_tft:1310873409093369877>"}},
	{"DIAMOND", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_diamond.png", "<:diamond_tft:1310873408094998600>"}},
	{"MASTER", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_master.png", "<:master_tft:1310873416504442880>"}},
	{"GRANDMASTER", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_grandmaster.png", "<:grandmaster_tft:1310873411756626001>"}},
	{"CHALLENGER", {"https://raw.communitydragon.org/latest/game/assets/ux/tftmobile/particles/tft_regalia_challenger.png", "<:challenger_tft:1310873407067521096>"}},
	{"UNRANKED", {"", "<:unranked_tft:1310873421617303612>"}}
};
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
	{"UNRANKED", dpp::colors::gray}	
};
	std::unordered_map<int, std::string> placementData = {
	{1,"FIRST"},
	{2,"SECOND"},
	{3,"THIRD"},
	{4,"FOURTH"},
	{5,"FIFTH"},
	{6,"SIXTH"},
	{7,"SEVENTH"},
	{8,"EIGHTH"}
};
	std::string defaultEmote = "<:steamhappy:1123798178030964848>";
};

#endif
