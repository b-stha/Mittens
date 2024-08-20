#include "data.h"

const std::unordered_map<std::string, std::vector<std::string>> unitData = {
    {"TFT12_Ahri", {"Ahri", ""}},
    {"TFT12_Akali", {"Akali", ""}},
    {"TFT12_Ashe", {"Ashe", ""}},
    {"TFT12_Bard", {"Bard", ""}},
    {"TFT12_Blitzcrank", {"Blitzcrank", ""}},
    {"TFT12_Briar", {"Briar", ""}},
    {"TFT12_Camille", {"Camille", ""}},
    {"TFT12_Cassiopeia", {"Cassiopeia", ""}},
    {"TFT12_Diana", {"Diana", ""}},
    {"TFT12_Elise", {"Elise", ""}},
    {"TFT12_Ezreal", {"Ezreal", ""}},
    {"TFT12_Fiora", {"Fiora", ""}},
    {"TFT12_Galio", {"Galio", ""}},
    {"TFT12_Gwen", {"Gwen", ""}},
    {"TFT12_Hecarim", {"Hecarim", ""}},
    {"TFT12_Hwei", {"Hwei", ""}},
    {"TFT12_Jax", {"Jax", ""}},
    {"TFT12_Jayce", {"Jayce", ""}},
    {"TFT12_Jinx", {"Jinx", ""}},
    {"TFT12_Kalista", {"Kalista", ""}},
    {"TFT12_Karma", {"Karma", ""}},
    {"TFT12_Kassadin", {"Kassadin", ""}},
    {"TFT12_Katarina", {"Katarina", ""}},
    {"TFT12_KogMaw", {"Kog'Maw", ""}},
    {"TFT12_Lillia", {"Lillia", ""}},
    {"TFT12_Milio", {"Milio", ""}},
    {"TFT12_Mordekaiser", {"Mordekaiser", ""}},
    {"TFT12_Morgana", {"Morgana", ""}},
    {"TFT12_Nami", {"Nami", ""}},
    {"TFT12_Nasus", {"Nasus", ""}},
    {"TFT12_Neeko", {"Neeko", ""}},
    {"TFT12_Nilah", {"Nilah", ""}},
    {"TFT12_Nomsy", {"Nomsy", ""}},
    {"TFT12_Norra", {"Norra & Yuumi", ""}},
    {"TFT12_Nunu", {"Nunu", ""}},
    {"TFT12_Olaf", {"Olaf", ""}},
    {"TFT12_Poppy", {"Poppy", ""}},
    {"TFT12_Rakan", {"Rakan", ""}},
    {"TFT12_Rumble", {"Rumble", ""}},
    {"TFT12_Ryze", {"Ryze", ""}},
    {"TFT12_Seraphine", {"Seraphine", ""}},
    {"TFT12_Shen", {"Shen", ""}},
    {"TFT12_Shyvana", {"Shyvana", ""}},
    {"TFT12_Smolder", {"Smolder", ""}},
    {"TFT12_Soraka", {"Soraka", ""}},
    {"TFT12_Swain", {"Swain", ""}},
    {"TFT12_Syndra", {"Syndra", ""}},
    {"TFT12_TahmKench", {"Tahm Kench", ""}},
    {"TFT12_Taric", {"Taric", ""}},
    {"TFT12_Tristana", {"Tristana", ""}},
    {"TFT12_Twitch", {"Twitch", ""}},
    {"TFT12_Varus", {"Varus", ""}},
    {"TFT12_Veigar", {"Veigar", ""}},
    {"TFT12_Vex", {"Vex", ""}},
    {"TFT12_Warwick", {"Warwick", ""}},
    {"TFT12_Wukong", {"Wukong", ""}},
    {"TFT12_Xerath", {"Xerath", ""}},
    {"TFT12_Yuumi", {"Yuumi", ""}},
    {"TFT12_Ziggs", {"Ziggs", ""}},
    {"TFT12_Zilean", {"Zilean", ""}},
    {"TFT12_Zoe", {"Zoe", ""}},
};

const std::unordered_map<std::string, std::string> itemData = {
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
	{"TFT_Item_GuinsoosRageblade", "<:guinsoos_rageblade:1250590494786846771>"},
	{"TFT_Item_InfinityEdge", "<:infinity_edge:1250682671357497454>"},
	{"TFT_Item_Deathblade", "<:death_blade:1250682711224614994>"},
	{"TFT_Item_ThiefsGloves", "<:thieves_gloves:1250590539322101830>"},
	{"TFT_Item_RapidFireCannon", "<:redbuff:1250590518354772048>"}, //Red Buff
	{"TFT_Item_ArchangelsStaff", "<:archangel_staff:1250590469784731720>"},
	{"TFT_Item_GargoyleStoneplate", "<:gargoyle_stoneplate:1250590490718638100>"},
	{"TFT_Item_Redemption", "<:redemption:1250718297301717035>"},
	{"TFT_Item_IonicSpark", "<:ionic_spark:1250590500461740125>"},
	{"TFT_Item_SteraksGage", "<:steraks_gage:1251321610842144809>"},
	{"TFT_Item_DragonsClaw", "<:dragons_claw:1250590484527710218>"},
	{"TFT_Item_BrambleVest", "<:bramble_vest:1250590474859712624>"},
	{"TFT_Item_SpearOfShojin", "<:spear_of_shojin:1251321487428817008>"},
	{"TFT_Item_Bloodthirster", "<:bloodthirster:1250590472754298970>"},
	{"TFT_Item_HextechGunblade", "<:hextech_gunblade:1250590497374867518>"},
	{"TFT_Item_Morellonomicon", "<:morellonomicon:1251321477270081568>"},
	{"TFT_Item_TitansResolve", "<:titans_resolve:1251321495049732168>"},
	{"TFT_Item_RunaansHurricane", "<:runaans_hurricane:1250590521999753276>"},
	{"TFT_Item_Crownguard", "<:crownguard:1250590481285648395>"},
	{"TFT_Item_AdaptiveHelm", "<:adaptive_helm:1250590468643750028>"},
	{"TFT_Item_BlueBuff", "<:blue_buff:1250590473828175983>"},
	{"TFT_Item_LastWhisper", "<:last_whisper:1250590503947341905>"},
	{"TFT_Item_JeweledGauntlet", "<:jeweled_guantlet:1251321475772977294>"},
	{"TFT_Item_Quicksilver", "<:quicksilver:1251321480537571348>"},
	{"TFT_Item_WarmogsArmor", "<:warmogs_armor:1250590543017152543>"},
	{"TFT_Item_StatikkShiv", "<:statikk_shiv:1250590528559386674>"},
	{"TFT_Item_GuardianAngel", "<:edge_of_night:1251321469636444180>"}, //Edge of Night
	{"TFT_Item_NightHarvester", "<:behemoth:1250590470690574379>"}, //Steadfast
	{"TFT_Item_SpectralGauntlet", "<:evenshroud:1250590487325184051>"}, //Evenshroud
	{"TFT_Item_Leviathan", "<:nashors_tooth:1250590507567157352>"}, //Nashor's Tooth
	{"TFT_Item_UnstableConcoction", "<:hand_of_justice:1251321473205927997>"}, //Hand of Justice
	{"TFT_Item_PowerGauntlet", "<:stridebreaker:1250590532397301830>"}, //Guardbreaker
	{"TFT_Item_RabadonsDeathcap", "<:rabadons_deathcap:1250590514617778318>"},
	{"TFT_Item_MadredsBloodrazor", "<:giant_slayer:1251321472350158868>"}, //Giant Slayer
	{"TFT_Item_FrozenHeart", "<:winters_approach:1251321613098553415>"}, //Protector's Vow
	{"TFT_Item_RedBuff", "<:sunfire_cape:1251321491543425116>"}, //Sunfire Cape

	//Spatula Items
	{"TFT_Item_ForceOfNature", "<:tacticians_crown:1250590535593492520>"},
	{"TFT11_Item_StoryweaverEmblemItem", "<:tft_set11_emblem_skyweaver:1251322233557745664>"},
	{"TFT11_Item_PorcelainEmblemItem", "<:tft_set11_emblem_porcelain:1251322197499314257>"},
	{"TFT11_Item_GhostlyEmblemItem", "<:tft_set11_emblem_ghostly:1251322191740666017>"},
	{"TFT11_Item_DryadEmblemItem", "<:tft_set11_emblem_dryad:1251322169322111048>"},
	{"TFT11_Item_FatedEmblemItem", "<:tft_set11_emblem_fated:1251322172480159794>"},
	{"TFT11_Item_UmbralEmblemItem", "<:tft_set11_emblem_umbral:1251322235667484713>"},
	{"TFT11_Item_MythicEmblemItem", "<:tft_set11_emblem_mythic:1251322196224118825>"},
	{"TFT11_Item_HeavenlyEmblemItem", "<:tft_set11_emblem_heavenly:1251322193049288776>"},

	//Uncraftable Emblems
	{"TFT11_Item_AltruistEmblemItem", "<:tft_set11_emblem_altruist:1251322164188020767>"},
	{"TFT11_Item_SpellslingerEmblemItem", "<:tft_set11_emblem_arcanist:1251322165274611752>"},
	{"TFT11_Item_WardenEmblemItem", "<:tft_set11_emblem_warden:1251322236795621467>"},
	{"TFT11_Item_InkShadowEmblemItem", "<:tft_set11_emblem_inkshadow:1251322194160521307>"},
	{"TFT11_Item_FortuneEmblemItem", "<:tft_set11_emblem_fortune:1251322190570192967>"},
	{"TFT11_Item_ReaperEmblemItem", "<:tft_set11_emblem_reaper:1251322214964527204>"},
	{"TFT11_Item_SageEmblemItem", "<:tft_set11_emblem_sage:1251322232500785192>"},
	{"TFT11_Item_DragonlordEmblemItem", "<:tft_set11_emblem_dragonlord:1251322168617340938>"},
	{"TFT11_Item_SniperEmblemItem", "<:tft_set11_emblem_sniper:1251322234732023818>"},
	{"TFT11_Item_ChallengerEmblemItem", "<:tft_set11_emblem_duelist:1251322171280855070>"},
	{"TFT11_Item_BehemothEmblemItem", "<:tft_set11_emblem_behemoth:1251322166301954078>"},
	{"TFT11_Item_InvokerEmblemItem", "<:tft_set11_emblem_invoker:1251322195297435729>"},
	{"TFT11_Item_BruiserEmblemItem", "<:tft_set11_emblem_bruiser:1251322167388536924>"},

	//Radiant Items
	{"TFT5_Item_WarmogsArmorRadiant", "<:warmogs_armor_radiant:1251370799835910164>"},
	{"TFT5_Item_DragonsClawRadiant", "<:dragons_claw_radiant:1251322462763876434>"},
	{"TFT5_Item_IonicSparkRadiant", "<:ionic_spark_radiant:1251322632859553913>"},
	{"TFT5_Item_QuicksilverRadiant", "<:quicksilver_radiant:1251322759473139752>"},
	{"TFT5_Item_HextechGunbladeRadiant", "<:hextech_gunblade_radiant:1251322509849006100>"},
	{"TFT5_Item_StatikkShivRadian", "<:statikk_shiv_radiant:1251322800115941426>"},
	{"TFT5_Item_FrozenHeartRadiant", "<:fimbulwinter_radiant:1251322466098352188>"}, //Radiant Protector's Vow
	{"TFT5_Item_BlueBuffRadiant", "<:blue_buff_radiant:1251322432867012669>"},
	{"TFT5_Item_ArchangelsStaffRadiant", "<:archangel_staff_radiant:1251322429125558353>"},
	{"TFT5_Item_MorellonomiconRadiant", "<:morellonomicon_radiant:1251322638593294346>"},
	{"TFT5_Item_BrambleVestRadiant", "<:bramble_vest_radiant:1251322433793949717>"},
	{"TFT5_Item_RunaansHurricaneRadiant", "<:runaans_hurricane_radiant:1251322764519014570>"},
	{"TFT5_Item_GuinsoosRagebladeRadiant", "<:guinsoos_rageblade_radiant:1251322469181292565>"},
	{"TFT5_Item_HandOfJusticeRadiant", "<:hand_of_justice_radiant:1251322508393713874>"},
	{"TFT5_Item_SunfireCapeRadiant", "<:sunfire_cape_radiant:1251322808844161105>"},
	{"TFT5_Item_LastWhisperRadiant", "<:last_whisper_radiant:1251322635674058772>"},
	{"TFT5_Item_ThiefsGlovesRadiant", "<:thieves_gloves_radiant:1251322809918029824>"},
	{"TFT5_Item_SteraksGageRadiant", "<:steraks_gage_radiant:1251322801357328405>"},
	{"TFT5_Item_RedemptionRadiant", "<:redemption_radiant:1251322763231105096>"},
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
	{"TFT4_Item_OrnnMuramana", "<:tft4_ornnitem_marksman_t3_murama:1251323059248431176>"},
	{"TFT9_Item_OrnnTrickstersGlass", "<:tft9_ornnitem_trickstersglass:1251323219580031057>"},
	{"TFT4_Item_OrnnAnimaVisage", "<:tft4_ornnitem_tank_t3_spiritvisa:1251323212286005278>"},
	{"TFT4_Item_OrnnInfinityForce", "<:tft4_ornnitem_fighter_t4_trinity:1251323027875041410>"},
	{"TFT9_Item_OrnnPrototypeForge", "<:tft9_ornnitem_blacksmithsgloves:1251323213506678835>"}, //Blacksmith's Gloves
	{"TFT4_Item_OrnnDeathsDefiance", "<:tft4_ornnitem_fighter_t3_deathsd:1251322998477291630>"},
	{"TFT9_Item_OrnnHorizonFocus", "<:tft9_ornnitem_snipersfocus:1251323218313085028>"}, //Sniper's Focus
	{"TFT_Item_Artifact_SpectralCutlass", "<:tft_item_artifact_spectralcutlas:1251322992550740038>"},
	{"TFT4_Item_OrnnZhonyasParadox", "<:tft4_ornnitem_mage_t3_zhonyashou:1251323056689905755>"},
	{"TFT_Item_Artifact_CursedBlade", "<:tft_item_artifact_cursedblade:1251322941870837820>"},
	{"TFT4_Item_OrnnEternalWinter", "<:tft4_ornnitem_mage_t4_everfrost:1251323058069966890>"},
	{"TFT9_Item_OrnnHullbreaker", "<:tft9_ornnitem_hullbreaker:1251323215771599001>"},
	{"TFT_Item_Artifact_LightshieldCrest", "<:tft_item_artifact_lightshieldcre:1251322966961295391>"},
	{"TFT_Item_Artifact_BlightingJewel", "<:tft_item_artifact_blightingjewel:1251322940830650439>"},
	{"TFT_Item_Artifact_TalismanOfAscension", "<:tft_item_artifact_talismanofasce:1251322994744229929>"},
	{"TFT_Item_Artifact_RapidFirecannon", "<:tft_item_artifact_rapidfirecanno:1251322972611022869>"},
	{"TFT_Item_Artifact_Mittens", "<:tft_item_artifact_mittens:1251322970010550354>"},
	{"TFT9_Item_OrnnDeathfireGrasp", "<:tft9_ornnitem_deathfiregrasp:1251323214680952922>"},
	{"TFT_Item_Artifact_WitsEnd", "<:tft_item_artifact_witsend:1251322996799307818>"},
	{"TFT_Item_Artifact_ProwlersClaw", "<:tft_item_artifact_prowlersclaw:1251322971587477534>"},
	{"TFT_Item_Artifact_SilvermereDawn", "<:tft_item_artifact_silvermeredawn:1251322991229276222>"},
	{"TFT_Item_Artifact_SeekersArmguard", "<:tft_item_artifact_seekersarmguar:1251322973428777012>"},
	{"TFT_Item_Artifact_CursedVampiricScepter", "<:tft_item_artifact_cursedvampiric:1251322942810361958>"},
	{"TFT7_Item_ShimmerscaleDiamondHands_HR", "<:tft10_diamondhands:1251323245722865674>"},
	{"TFT_Item_Artifact_Fishbones", "<:tft_item_artifact_fishbones:1251322943804280975>"},
	{"TFT_Item_Artifact_ForbiddenIdol", "<:tft_item_artifact_forbiddenidol:1251322945259831296>"},
	{"TFT7_Item_ShimmerscaleGamblersBlade_HR", "<:tft10_gamblersblade:1251323222499262504>"},
	{"TFT4_Item_OrnnTheCollector", "<:tft4_ornnitem_marksman_t3_thecol:1251323109840257056>"},
	{"TFT_Item_Artifact_InnervatingLocket", "<:tft_item_artifact_innervatingloc:1251322964658487408>"},
	{"TFT_Item_Artifact_LichBane", "<:tft_item_artifact_lichbane:1251322965987950644>"},
	{"TFT_Item_Artifact_LudensTempest", "<:tft_item_artifact_ludenstempest:1251322968190095410>"},
	{"TFT_Item_Artifact_HorizonFocus", "<:tft_item_artifact_horizonfocus:1251322946337902653>"}, //Horizon's Focus
	{"TFT_Item_Artifact_UnendingDespair", "<:tft_item_artifact_unendingdespai:1251322995851526185>"},
	{"TFT_Item_Artifact_SuspiciousTrenchCoat", "<:tft_item_artifact_suspicioustren:1251322993553047643>"},

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

    //Inkshadow Tattoos
    {"TFT11_Item_InkshadowOx", "<:tft11_inkshadow_vitality:1259365786699698206>"},
    {"TFT11_Item_InkshadowHorse", "<:tft11_inkshadow_force:1259365543820001352>"},
    {"TFT11_Item_InkshadowRat", "<:tft11_inkshadow_bombardment:1259365542557651065>"},
    {"TFT11_Item_InkshadowPig", "<:tft11_inkshadow_protection:1259365546202497044>"},
    {"TFT11_Item_InkshadowSnake", "<:tft11_inkshadow_toxin:1259365785369972838>"},
    {"TFT11_Item_InkshadowTiger", "<:tft11_inkshadow_fury:1259365545254588478>"}
};

const std::unordered_map<std::string, std::vector<std::string>> augmentData = {
	{"TFT11_Augment_GoldenRemover", {"The Golden Remover","<:goldenremover_i:1251762777358336021>"}},
	{"", {"A Golden Quest",""}},
	{"", {"AFK",""}},
	{"", {"Aggressive Perseverance",""}},
	{"", {"All That Shimmers",""}},
	{"", {"All That Shimmers+",""}},
	{"", {"An Upgraded Adventure",""}},
	{"", {"Anger Issues",""}},
	{"", {"Arcana Crest",""}},
	{"", {"Arcana Crown",""}},
	{"", {"Arcane Conduit",""}},
	{"TFT9_Augment_Commander_Ascension", {"Ascension","<:ascension2:1251323391739170919>"}},
	{"", {"Assassin's Toolbox",""}},
	{"", {"At What Cost",""}},
	{"", {"Avenge The Fallen",""}},
	{"TFT9_Augment_BalancedBudget2", {"Balanced Budget","<:balancedbudgetii:1251323396105699348>"}},
	{"TFT9_Augment_BalancedBudgetPlus", {"Balanced Budget+","<:balancedbudgetii:1251323396105699348>"}},
	{"TFT7_Augment_BandOfThieves1", {"Band of Thieves I","<:bandthieves1:1251323397443551304>"}},
	{"", {"Bastion Crest",""}},
	{"", {"Bastion Crown",""}},
	{"", {"Bee-st Friends",""}},
	{"", {"Beggars Can Be Choosers",""}},
	{"TFT10_Augment_BigGains", {"Big Gains","<:biggainsii:1251323452842053662>"}},
	{"TFT9_Augment_BigGrabBag", {"Big Grab Bag","<:grabbagii:1251347707856031804>"}},
	{"TFT7_Augment_BirthdayPresents", {"Birthday Present","<:goldengiftsiii:1251347582387622081>"}},
	{"TFT9_Augment_BlindingSpeed", {"Blinding Speed","<:berserkiii:1251323433023701064>"}},
	{"TFT9_Augment_RedBuff", {"Blistering Strikes","<:redbuffi:1251348646994382888>"}},
	{"", {"Blossoming Lotus I",""}},
	{"", {"Blossoming Lotus II",""}},
	{"TFT_Augment_BranchingOut", {"Branching Out","<:branchingouti:1251323455899697213>"}},
	{"TFT11_Augment_Buildabud", {"Build a Bud!","<:buildabud_iii:1251323457434812436>"}},
	{"TFT6_Augment_Traitless2", {"Built Different II","<:builtdifferent2:1251323460232282112>"}},
	{"TFT9_Augment_BuildingACollectionPlusPlus", {"Buried Treasures III","<:buriedtreasuresiii:1251324876707332167>"}},
	{"", {"Called Shot",""}},
	{"TFT11_Augment_Calltochaos", {"Call to Chaos","<:calltochaos_iii:1251324879630897173>"}},
	{"TFT9_Augment_CapriciousForge", {"Capricious Forge","<:prototypeforgeii:1251348596742164511>"}},
	{"", {"Caramelized Comforts",""}},
	{"TFT9_Augment_BardPlaybook1", {"Caretaker's Ally","<:caretaker_schoseni:1251324881124065381>"}},
	{"TFT9_Augment_BardPlaybook3", {"Caretaker's Chosen","<:caretaker_schoseniii:1251324882617237644>"}},
	{"TFT9_Augment_BardPlaybook2", {"Caretaker's Favor","<:caretaker_schosenii:1251761972802748479> "}},
	{"", {"Category Five",""}},
	{"", {"Cauterize",""}},
	{"", {"Chrono Crest",""}},
	{"", {"Chrono Crown",""}},
	{"TFT6_Augment_ClearMind", {"Clear Mind","<:clearmind2:1251324884085375047>"}},
	{"", {"Clockwork Accelerator",""}},
	{"TFT7_Augment_ClutteredMind", {"Cluttered Mind","<:dizzyii:1251347464871477438>"}},
	{"", {"Combat Bandages I",""}},
	{"", {"Combat Bandages II",""}},
	{"TFT9_Augment_CombatCaster", {"Combat Caster","<:combatcasterii:1251324885444329645>"}},
	{"TFT9_Augment_CustomerIsAlwaysRight", {"Component Buffet","<:thecustomerisalwaysrighti:1251377626564788265>"}},
	{"TFT10_Augment_CrashTestDummies", {"Crash Test Dummies","<:crashtestdummiesii:1251324994643038321>"}},
	{"TFT10_Augment_CrownGuarded", {"Crown Guarded","<:crownguardedii:1251347320235360367>"}},
	{"", {"Dark Alley Dealings",""}},
	{"", {"Defensive Arts",""}},
	{"", {"Deja Vu",""}},
	{"", {"Deja Vu+",""}},
	{"", {"Double Down",""}},
	{"", {"Draconic Mastery",""}},
	{"TFT11_Augment_DragonSpirit", {"Dragon's Spirit","<:dragonsspirit_ii:1251347466037755904>"}},
	{"", {"Dual Purpose",""}},
	{"", {"Duo Queue",""}},
	{"", {"Eldritch Crest",""}},
	{"", {"Eldritch Crown",""}},
	{"", {"Endless Hunt",""}},
	{"TFT11_Augment_Epoch", {"Epoch","<:epoch_ii:1251347507351654510>"}},
	{"TFT11_Augment_EpochPlus", {"Epoch+","<:epoch_ii:1251347507351654510>"}},
	{"TFT9_Augment_EscortQuest", {"Escort Quest","<:escortquestii:1251347508349632552>"}},
	{"", {"Eternal Growth",""}},
	{"", {"Eternal Growth+",""}},
	{"TFT6_Augment_Distancing", {"Exiles I","<:exiles1:1251347510648373301>"}},
	{"", {"Explosive Growth",""}},
	{"", {"Explosive Growth+",""}},
	{"", {"Faerie Crest",""}},
	{"", {"Faerie Crown",""}},
	{"", {"Fast Forward",""}},
	{"TFT6_Augment_Featherweights1", {"Featherweights I","<:featherweights1:1251347512166715433>"}},
	{"TFT9_Augment_Commander_FinalAscension", {"Final Ascension","<:ascension3:1251323393291063398>"}},
	{"", {"Final Resistance",""}},
	{"", {"Find Your Center",""}},
	{"TFT11_Augment_FineVintage", {"Fine Vintage","<:finevintage_i:1251347513370345592>"}},
	{"", {"Flexible",""}},
	{"", {"Fortune Favors the Bold",""}},
	{"", {"Frost Crest",""}},
	{"", {"Frost Crown",""}},
	{"", {"Frosty Frontline",""}},
	{"", {"Giang and Mighty",""}},
	{"TFT10_Augment_GoingLong", {"Going Long","<:goinglongiii:1251347579602735124>"}},
	{"TFT10_Augment_GoodForSomethingSilver", {"Good For Something I","<:goodforsomethingi:1251347607742054531>"}},
    {"", {"Hard Commit", ""}},
	{"TFT9_Augment_HedgeFund", {"Hedge Fund","<:richgetricher3:1251348651742199880>"}},
	{"TFT10_Augment_HelpIsOnTheWay", {"Help Is On The Way","<:helpisonthewayi:1251347783227670559>"}},
	{"TFT10_Augment_HeroicGrabBag", {"Heroic Grab Bag","<:heroicgrabbagii:1251347784578236518>"}},
    {"", {"High Horsepower", ""}},
    {"", {"High Voltage", ""}},
    {"", {"Higher Education", ""}},
    {"", {"Honeymancy Crest", ""}},
    {"", {"Honeymancy Crown", ""}},
    {"", {"Hunter Crest", ""}},
    {"", {"Hunter Crown", ""}},
    {"", {"I'm The Carry Now", ""}},
    {"", {"Immovable Object", ""}},
	{"TFT9_Augment_ImpenetrableBulwark", {"Impenetrable Bulwark","<:standbehind3:1251377587289194588>"}},
    {"", {"Incantor Crest", ""}},
    {"", {"Incantor Crown", ""}},
	{"TFT10_Augment_InspiringEpitaph", {"Inspiring Epitaph","<:inspiringepitaphii:1251347786964795445>"}},
    {"", {"Invested+", ""}},
    {"", {"Invested++", ""}},
	{"TFT9_Augment_IronAssets", {"Iron Assets","<:ironassetsi:1251347818862612561>"}},
    {"", {"Item Collector I", ""}},
    {"", {"Item Collector II", ""}},
    {"", {" ", ""}},
	{"TFT6_Augment_ItemGrabBag1", {"Item Grab Bag I", "<:itemgrabbag1:1251347819969642516>"}},
    {"", {"Item Ladder", ""}},
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
    {"", {"Mage Crest", ""}},
    {"", {"Mage Crown", ""}},
	{"TFT9_Augment_OldMansWalkingStick", {"Magic Wand", "<:oldman_swalkingstickii:1251348220718878770>"}},
	{"TFT6_Augment_SlowAndSteady", {"March of Progress", "<:slowandsteady3:1251377584877604907>"}},
    {"", {"Marksman's Toolbox", ""}},
	{"TFT9_Augment_Martyr", {"Martyr", "<:martyrii:1251348143715389561>"}},
    {"", {"Mentorship I", ""}},
    {"", {"Mentorship II", ""}},
	{"TFT6_Augment_MetabolicAccelerator", {"Metabolic Accelerator", "<:metabolicaccel2:1251348213265334313>"}},
	{"TFT9_Augment_MissedConnections", {"Missed Connections", "<:missedconnectionsi:1251348215484387429>"}},
    {"", {"Molten Caramel", ""}},
    {"", {"Multistriker Crest", ""}},
    {"", {"Multistriker Crown", ""}},
	{"TFT6_Augment_ForceOfNature", {"New Recruit", "<:newrecruit3:1251348218470600704>"}},
	{"TFT9_Augment_NotToday", {"Not Today", "<:nottodayii:1251348219728887839>"}},
    {"", {"On The House", ""}},
	{"TFT6_Augment_OneTwoFive", {"One, Two,Five!", "<:onetwofivei:1251348221339369543>"}},
	{"TFT9_Augment_OneTwosThree", {"Ones Twos Three", "<:threescompanyi:1251377670563041291>"}},
	{"TFT11_Augment_OverEncumbered", {"Over Encumbered", "<:overencumbered_i:1251348505084039199>"}},
	{"TFT6_Augment_PandorasItems", {"Pandora's Items", "<:pandora1:1251348506212434011>"}},
	{"TFT9_Augment_PandorasItems2", {"Pandora's Items II", "<:pandora2:1251348507210678302>"}},
	{"TFT9_Augment_PandorasRadiantBox", {"Pandora's Items III", "<:pandora3:1251348508238418012>"}},
	{"TFT9_Augment_Commander_PartialAscension", {"Partial Ascension", "<:ascension1:1251323390556635220>"}},
    {"", {"Patience is a Virtue", ""}},
	{"TFT9_Augment_LearningFromExperience2", {"Patient Study", "<:learningfromexperienceii:1251347894485782569>"}},
	{"TFT9_Augment_PhreakyFriday", {"Phreaky Friday", "<:phreakyfridayiii:1251348509479927808>"}},
	{"TFT9_Augment_PhreakyFridayPlus", {"Phreaky Friday+", "<:phreakyfridayiii:1251348509479927808>"}},
    {"", {"Pilfer", ""}},
    {"", {"Placebo", ""}},
    {"", {"Placebo", ""}},
	{"TFT6_Augment_PortableForge", {"Portable Forge", "<:portableforge2:1251348512415944755>"}},
    {"", {"Portal Crest", ""}},
    {"", {"Portal Crown", ""}},
    {"", {"Potions 201", ""}},
    {"", {"Practice Partners", ""}},
    {"", {"Precise Planning", ""}},
    {"", {"Preserver Crest", ""}},
    {"", {"Preserver Crown", ""}},
    {"", {"Press The Attack", ""}},
	{"TFT6_Augment_GachaAddict", {"Prismatic Ticket", "<:goldenticket3:1251347584774045726>"}},
	{"TFT11_Augment_Prizefighter", {"Prizefighter", "<:prizefighter_ii:1251348513581957154>"}},
	{"TFT9_Augment_PumpingUp", {"Pumping Up I", "<:pumpingupi:1251348597967163473>"}},
	{"TFT9_Augment_PumpingUp2", {"Pumping Up II", "<:pumpingupii:1251348599183249428>"}},
	{"TFT9_Augment_PumpingUp3", {"Pumping Up III", "<:pumpingupiii:1251348600605376623>"}},
    {"", {"Pyro Crest", ""}},
    {"", {"Pyro Crown", ""}},
	{"TFT11_Augment_RadiantRefactor", {"Radiant Refactor", "<:radiantrefactor_iii:1251348601649627263>"}},
	{"TFT6_Augment_RadiantRelics", {"Radiant Relics", "<:radiantreliciii:1251348602757058682>"}},
	{"TFT11_Augment_Behemoth", {"Raid Boss", "<:raidboss_ii:1251348604015087627>"}},
	{"TFT11_Augment_RainingGold", {"Raining Gold", "<:raininggold_ii:1251348605390815272>"}},
	{"TFT11_Augment_RainingGoldPlus", {"Raining Gold+", "<:raininggold_ii:1251348605390815272>"}},
	{"TFT6_Augment_Recombobulator", {"Recombobulator", "<:recombobulatori:1251348645651943506>"}},
	{"TFT11_Augment_Reinfourcement", {"ReinFOURcement", "<:reinfourcement_ii:1251348650295296110>"}},
    {"", {"Replication", ""}},
    {"", {"Restart Mission", ""}},
	{"TFT9_Augment_RiskyMoves", {"Risky Moves", "<:riskymovesi:1251348652945969265>"}},
	{"TFT9_Augment_RollTheDice", {"Roll The Dice", "<:rollingfordaysi:1251348653789155369>"}},
	{"TFT9_Augment_Commander_RollingForDays", {"Rolling For Days I", "<:rollthediceiii:1251348689700782130>"}},
    {"", {"Row Rejuvenation I", ""}},
    {"", {"Row Rejuvenation II", ""}},
    {"", {"Royal Guard", ""}},
	{"TFT10_Augment_Scapegoat", {"Scapegoat", "<:thescapegoatii:1251377667144417310>"}},
    {"", {"Scholar Crest", ""}},
    {"", {"Scholar Crown", ""}},
    {"", {"School Mascot", ""}},
	{"TFT11_Augment_ScoreboardScrapper", {"Scoreboard Scrapper", "<:scoreboardscrapper_ii:1251348691898597497>"}},
    {"", {"Shapeshifter Crest", ""}},
    {"", {"Shapeshifter Crown", ""}},
    {"", {"Shields Up", ""}},
    {"", {"Shimmerscale Essence", ""}},
	{"TFT9_Augment_SilverSpoon", {"Silver Spoon", "<:silverspooni:1251348695568351243>"}},
	{"TFT9_Augment_BronzeTicket", {"Silver Ticket", "<:goldenticket1:1251347583494914088>"}},
	{"TFT10_Augment_SilverVeil", {"Silver Veil", "<:thesilverveili:1251377668390391808>"}},
	{"TFT11_Augment_Slammin", {"Slammin'", "<:slammin_ii:1251348697313447966>"}},
	{"TFT11_Augment_Slammin_Plus", {"Slammin'+", "<:slammin_ii:1251348697313447966>"}},
	{"TFT9_Augment_Sleightofhand", {"Sleight of Hand", "<:sleightofhandii:1251377556263796859>"}},
    {"", {"Spellblades", ""}},
    {"", {"Spellcaster's Toolbox", ""}},
    {"", {"Spider Queen", ""}},
    {"", {"Spin to Win", ""}},
    {"", {"Spoils of War I", ""}},
    {"", {"Spoils of War II", ""}},
    {"", {"Spoils of War III", ""}},
	{"TFT6_Augment_Diversify2", {"Stand United II", "<:standunited2:1251377588698484806>"}},
	{"TFT9_Augment_StarsAreBorn", {"Stars are Born", "<:starsarebornii:1251377590049177701>"}},
	{"TFT9_Augment_StationarySupport1HR", {"Stationary Support I", "<:stationarysupporti:1251377592397860894>"}},
	{"TFT10_Augment_Stimpack", {"Stimpack", "<:stimpacki:1251377618620645386>"}},
    {"", {"Subscription Service", ""}},
    {"", {"Sugarcraft Crest", ""}},
    {"", {"Sugarcraft Crown", ""}},
	{"TFT9_Augment_SupportCache", {"Support Cache", "<:supportcacheii:1251377621028175922>"}},
    {"", {"Support Golem I", ""}},
    {"", {"Support Golem II", ""}},
    {"", {"Sweet Tooth", ""}},
    {"", {"Sweet Tooth+", ""}},
	{"TFT9_Augment_ArmyBuilding", {"Team Building", "<:buildinganarmyi:1251323459028521030>"}},
	{"TFT9_Augment_Commander_TeamingUp1", {"Teaming Up I", "<:teamingupi:1251377623758540882>"}},
	{"TFT9_Augment_Commander_TeamingUp2", {"Teaming Up II", "<:teamingupii:1251377625398644827>"}},
	{"TFT6_Augment_TheGoldenEgg", {"The Golden Egg", "<:thegoldeneggiii:1251377664204472330>"}},
    {"", {"Thorn-Plated Armor", ""}},
	{"TFT6_Augment_ThreesCompany", {"Three's Company", "<:threescompanyii:1251377672261730314>"}},
	{"TFT9_Augment_ThreesACrowd", {"Three's a Crowd", "<:three_sacrowdii:1251377669778571394>"}},
	{"TFT9_Augment_TiniestTitan", {"Tiniest Titan", "<:tiniesttitaniii:1251377673599455305>"}},
	{"TFT9_Augment_TiniestTitanPlus", {"Tiniest Titan+", "<:tiniesttitaniii:1251377673599455305>"}},
	{"TFT6_Augment_TinyTitans", {"Tiny Titans", "<:tinytitansi:1251377709725253693>"}},
	{"TFT11_Augment_TinyButDeadly", {"Tiny, but Deadly", "<:tinybutdeadly_iii:1251377708324225096>"}},
	{"TFT6_Augment_TradeSector", {"Trade Sector", "<:trade2:1251377713873293332>"}},
    {"", {"Trait Tracker", ""}},
    {"", {"Transfiguration", ""}},
	{"TFT6_Augment_TriForce1", {"Tri Force I", "<:triforcei:1251377715798343711>"}},
	{"TFT9_Augment_TwoHealthy", {"Two Healthy", "<:twohealthyii:1251377759863705642>"}},
    {"", {"Two Tanky", ""}},
	{"TFT9_Augment_Formation1", {"Unified Resistance I", "<:redroveri:1251348648076251176>"}},
	{"TFT9_Augment_Formation2", {"Unified Resistance II", "<:redroverii:1251348649146056795>"}},
    {"", {"Unleash The Beast", ""}},
    {"", {"Upward Mobility", ""}},
    {"", {"Vanguard Crest", ""}},
    {"", {"Vanguard Crown", ""}},
    {"", {"Vertically Inclined", ""}},
	{"TFT11_Augment_WanderingTrainerGold", {"Wandering Trainer I", "<:wanderingtrainerii:1251377762157989908>"}},
	{"TFT9_Augment_WanderingTrainer", {"Wandering Trainer II", "<:wanderingtraineriii:1251377763642769468>"}},
    {"", {"Warrior Crest", ""}},
    {"", {"Warrior Crown", ""}},
	{"TFT9_Augment_WhatDoesntKillYou", {"What Doesn't Kill You", "<:whatdoesn_tkillyouii:1251377766147031064>"}},
    {"", {"What Doesn't Kill You", ""}},
    {"", {"What the Forge", ""}},
    {"", {"Witchcraft Crest", ""}},
    {"", {"Witchcraft Crown", ""}},
    {"", {"Witchy Wallop", ""}},
    {"", {"Worth the Wait", ""}},
    {"", {"Worth the Wait II", ""}},
	{"TFT9_Augment_YouHaveMyBow", {"You Have My Bow", "<:youhavemybowii:1251377769074528276>"}},
	{"TFT9_Augment_YouHaveMySword", {"You Have My Sword", "<:youhavemyswordii:1251377794340880485>"}},
	{"TFT9_Augment_YoungAndWildAndFree", {"Young and Wild and Free", "<:youngandwildandfreei:1251377795485925416>"}}
    {"", {"Zap Attack", ""}},
};