#include "bot.h"
#include "helpers.h"
#include "RiotAPI.h"
#include "apikeys.h"

Bot::Bot()
		: botCluster(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content) {
	botCluster.on_log(dpp::utility::cout_logger());
	readyHandler();
	registerCommands();
}	

void Bot::run() {
	botCluster.start(dpp::st_return);
}

void Bot::registerCommands() {
    botCluster.on_slashcommand([this](const dpp::slashcommand_t& event) {
		const auto commandName = event.command.get_command_name();
        if (commandName == "ping") {
            event.reply("Pong!");
			return;
        }
		if (commandName == "add") {
			dpp::command_interaction cmd_data = std::get<dpp::command_interaction>(event.command.data);
			dpp::snowflake currChannel = event.command.channel_id;
			std::string userInput = std::get<std::string>(cmd_data.options[0].value);
			std::cout << userInput << std::endl;
			std::vector<std::string> userInputArr;

			if (userInput.find("#") != std::string::npos) { 
				userInputArr = split(userInput, '#');
			}
			else {
				userInputArr.emplace_back(userInput);
				userInputArr.emplace_back("NA1");
			}
			
			try {
				std::string puuid = fetchPUUID(userInputArr[0], userInputArr[1], TFT_APIKEY);
				if (notPlayerExists(this->userVec, puuid)) {
					auto pPlayer = std::make_unique<Player>(puuid);
					pPlayer->setChannelID(currChannel);
					pPlayer->setNameTag(userInputArr[0], userInputArr[1]);

					std::string summonerID = fetchSummonerID(puuid, TFT_APIKEY);
					pPlayer->setSummonerID(summonerID);
					League initLeague = fetchLeague(*pPlayer, TFT_APIKEY);
					pPlayer->setPlayerRank(initLeague);
					this->userVec.push_back(std::move(pPlayer));
					event.reply(userInput + " successfully added");
				}
				else {
					event.reply(userInput + " already exists.");
				}
			}
			catch (const std::exception& e) {
				std::cout << e.what() << std::endl; 
				event.reply(userInput + " not found...");
			}
		}
    });
}

void Bot::readyHandler() {
    botCluster.on_ready([this](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            botCluster.global_command_create(dpp::slashcommand("ping", "Ping pong!", botCluster.me.id));

            dpp::slashcommand add;
            add.set_name("add");
            add.set_description("Format as name#tagline.");
            add.add_option(
                dpp::command_option(dpp::co_string, "username", "name#tag", true)
            );

            botCluster.global_command_create(add, [this](const dpp::confirmation_callback_t& callback) {
                if (callback.is_error()) {
                    std::cout << callback.http_info.body << "\n";
                }
                });
        }
    });
}

/*
std::string augListStr(const Player& player) {
	std::string augListOutput = "";

	if (player.myMatchInfo.augments.empty()) {
		return "None";
	}

	for (const auto& augment : player.myMatchInfo.augments) {
        if (augmentData.count(augment) > 0) {
		    augListOutput += augmentData.at(augment)[1] + " " + augmentData.at(augment)[0] + "\n";
                continue;
            }
            augListOutput += "<:steamhappy:1123798178030964848> Placeholder Augment \n";
	}
	return augListOutput;
};*/

void Bot::unitListStr(const Player& player, dpp::embed& embedObj, const Data& data) {
	for (const auto& unit : player.myMatchInfo.units) {
		std::string apiName = unit.characterID, unitName, unitIconName;
		std::unordered_map<std::string, UnitInfo> unitData = data.getCDragonData().getUnitData();
		const auto it = unitData.find(apiName);
		if (it != unitData.end()) {
			unitName = it->second.getName();
			unitIconName = it->second.getEmote() + " " + unitName;
		} else {
			unitName = "null";
			unitIconName = data.getDefaultEmote() + " " + unitName;
		}

		unitName = setStrWidth(unitName, 10);
		std::string unitItems = itemListStr(unit, data);
		embedObj.add_field(
			"", 
			starCount(unit.tier) + "\n" + 
			unitIconName + "\n" +
			unitItems + "\n",
			true);
	}
};

void Bot::traitListStr(const Player& player, dpp::embed& embedObj, const Data& data) {
	for (const auto& trait : player.myMatchInfo.traits) {
		if (trait.style != 0) {
			std::string traitName, traitIcon;
			int currBreakpoint;
			const auto& traitData = data.getCDragonData().getTraitData();
			const auto it = traitData.find(trait.apiName);
			if (it != traitData.end()) {
				traitName = it->second.getName();
				const auto& styles = it->second.getStyles();
				const auto innerIt = styles.find(trait.style);
				if (innerIt != styles.end()) {
					traitIcon = innerIt->second;
				} else {
					traitIcon = data.getDefaultEmote();
				}
				int traitIdx = trait.level - 1;
				const auto& breakpoints = it->second.getBreakpoints();
				if (traitIdx >= 0 && traitIdx < breakpoints.size()) {
					currBreakpoint = breakpoints[trait.level - 1];
				}
				else {
					currBreakpoint = 0;
				}
			} else {
				traitName = "null";
				traitIcon = data.getDefaultEmote();
				currBreakpoint = 0;
			}

			traitName = setStrWidth(traitName, 10);
			embedObj.add_field(
				"", 
				traitIcon + " " + std::to_string(trait.numUnits) + "/" + std::to_string(currBreakpoint) + " " + traitName,
				true);
		}
	};
};

std::string Bot::itemListStr(const Unit& unit, const Data& data) {
	std::string itemListOutput = "";
	std::string emptyItem = "<:transparent:1250910469330567292>";
	if (unit.items.empty()) {
		itemListOutput += (emptyItem * 3);
	}
	else {
		const auto& itemEmotes = data.getItemEmotes();
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

dpp::embed Bot::createResult(const Player& player, const Data& data) {
    std::string name = player.getFullName()[0];
	std::string profileURL = "https://tactics.tools/player/na/" + fillSpaces(name) + "/" + player.getFullName()[1] + "/";
	std::string matchResultURL = profileURL + player.getCurrMatch();
	//std::string augmentList = augListStr(player);
	std::string playerTier = player.getPlayerRank().first;
	dpp::embed outEmbed = dpp::embed()
		.set_color(data.getRankColor().at(playerTier))
		.set_title(data.getPlacementData().at(player.myMatchInfo.placement) + " PLACE")
		.set_url(matchResultURL)
		.set_author(name + "'s match result", profileURL, "")
		.set_thumbnail("https://ddragon.leagueoflegends.com/cdn/13.24.1/img/tft-tactician/Tooltip_TFTAvatar_BubbleTea_BubbleTea_Tier1.LL_TFTAvatar_BubbleTea.png")
		.add_field(
			data.getRankData().at(playerTier)[1] + " " + playerTier + " " + player.getPlayerRank().second + " (" + std::to_string(player.getPlayerLP().second) + " LP)" ,
			"\n"
			"Duration: " + std::to_string(player.getTime()[0]) + ":" + std::to_string(player.getTime()[1]) + "\n"
			"Level: " + std::to_string(player.myMatchInfo.level) + "\n"
			"Gold Left: " + std::to_string(player.myMatchInfo.goldLeft) + "\n"
			"Board Value: " + std::to_string(player.myMatchInfo.boardValue),
			false
		)/*
		.add_field(
			"Augments",
			augmentList,
			false
		)*/
		.add_field(
			"Traits",
			"",
			false
		);
	traitListStr(player, outEmbed, data);
	outEmbed
		.add_field(
			"Units",
			"",
			false
		);
	unitListStr(player, outEmbed, data);

	return outEmbed;
};

dpp::embed Bot::createPromoMsg(const Player& player, const Data& data) {
	std::string playerTier = player.getPlayerRank().first;
	std::string name = player.getFullName()[0];
	dpp::embed promoEmbed = dpp::embed()
		.set_color(data.getRankColor().at(playerTier))
		.set_title("PROMOTION")
		.set_thumbnail(data.getRankData().at(playerTier)[0])
		.add_field(
			name + " has promoted to " + playerTier,
			"",
			false
		);

	return promoEmbed;
};