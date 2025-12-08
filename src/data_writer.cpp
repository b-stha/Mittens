#include "data.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
using json = nlohmann::json;

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


int main() {
    std::string url, set;

    std::string unitAPIName;

    std::string traitAPIName;

    json outJson;

    std::cout << "Enter link to data: ";
    std::getline(std::cin, url);
    std::cout << "Enter set number: ";
    std::getline(std::cin, set);
    json raw = makeReq(url, 10, 1000);


    for (auto& unit : raw["sets"][set]["champions"]) {
        unitAPIName = unit["apiName"];

        outJson["unitData"][unitAPIName] = "";
    }

    for (auto& trait : raw["sets"][set]["traits"]) {
        traitAPIName = trait["apiName"];
        std::unordered_map<std::string, std::string> traitStyles;

        for (auto& level : trait["effects"]) {
            std::string style = std::to_string(level["style"].get<int>());
            traitStyles[style] = "";

        }
        outJson["traitData"][traitAPIName] = traitStyles;
    }
    std::cout << "So far so good..." << std::endl;
    for (auto& [key, value] : itemEmotes) {
        outJson["itemEmotes"][key] = value;
    }
    std::cout << "All done! Writing to setdata.json..." << std::endl;
    std::ofstream out("setdata.json");
    out << outJson.dump(4);
    std::cout << "Finished writing to setdata.json" << std::endl;
    return 0;
}
