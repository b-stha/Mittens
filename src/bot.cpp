#include "bot.h"
#include "RiotAPI.h"
#include "apikeys.h"
#include "data.h"
#include "Player.h"
#include "helpers.h"
#include "Worker.h"

Bot::Bot()
		: botCluster(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content), riotAPI(botCluster, TFT_APIKEY), pWorker(std::make_unique<Worker>(this)){
	;
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
			
			riotAPI.fetchPUUID(userInputArr[0], userInputArr[1], [this, userInput, currChannel, userInputArr, &event](const std::string& puuid) {
				if (notPlayerExists(this->userVec, puuid)) {
					auto pPlayer = std::make_unique<Player>(puuid);
					pPlayer->setChannelID(currChannel);
					pPlayer->setNameTag(userInputArr[0], userInputArr[1]);

					riotAPI.fetchSummonerID(*pPlayer);
					riotAPI.fetchLeague(*pPlayer, [this, pPlayer = pPlayer.get(), &event, userInput]() {
						this->userVec.push_back(std::move(std::unique_ptr<Player>(pPlayer)));
						event.reply(userInput + " successfully added");
					});
				}
				else {
					event.reply(userInput + " already exists.");
				}
			});
		}
	});
}

void Bot::readyHandler() {
    botCluster.on_ready([this](const dpp::ready_t& event) {
		std::thread([this]() {
			auto fData = Data::asyncCreateData(botCluster);
			try {
				auto readyData = fData.get();
				this->pLoadedData = std::move(readyData);
				this->isReady.store(true);
			} catch (const std::exception& e) {
				std::cerr << "Data initialization failed: " << e.what() << std::endl;
			}

		}).detach();
	});
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
};

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
	for (const auto& unit : player.getMatchInfo().units) {
		std::string apiName = unit.characterID, unitName, unitIconName;
		std::unordered_map<std::string, UnitInfo> unitData = data.getUnitData();
		const auto it = unitData.find(apiName);
		if (it != unitData.end()) {
			unitName = it->second.name;
			unitIconName = data.getEmote(apiName) + " " + unitName;
		} else {
			unitName = "null";
		}

		unitName = setStrWidth(unitName, 10);
		std::string unitItems = "";
		std::string emptyItem = "<:transparent:1250910469330567292>";
		if (unit.items.empty()) {
			unitItems += (emptyItem * 3);
		}
		else {
			for (const auto& item : unit.items) {
				unitItems += data.getEmote(item) + " "; 
			}
		}

		embedObj.add_field(
			"", 
			starCount(unit.tier) + "\n" + 
			unitIconName + "\n" +
			unitItems + "\n",
			true);
	}
};

void Bot::traitListStr(const Player& player, dpp::embed& embedObj, const Data& data) {
	for (const auto& trait : player.getMatchInfo().traits) {
		if (trait.style != 0) {
			std::string traitName, traitIcon;
			int currBreakpoint;
			const auto& traitData = data.getTraitData();
			const auto it = traitData.find(trait.apiName);
			if (it != traitData.end()) {
				traitName = it->second.name;
				traitIcon = data.getEmote(trait.apiName + "_" + std::to_string(trait.style));
				int traitIdx = trait.level - 1;
				const auto& breakpoints = it->second.breakpoints;
				if (traitIdx >= 0) {
					if (static_cast<size_t>(traitIdx) < breakpoints.size()) {
					currBreakpoint = breakpoints[traitIdx];
					} else {
						currBreakpoint = 0;
					}
				}
			} else {
				traitName = "null";
				currBreakpoint = 0;
			}

			traitName = setStrWidth(traitName, 10);
			embedObj.add_field(
				"", 
				traitIcon + " " + std::to_string(trait.numUnits) + "/" + std::to_string(currBreakpoint) + " " + traitName,
				true);
		}
	}
}

dpp::embed Bot::createResult(const Player& player, const Data& data) {
    std::string name = player.getFullName()[0];
	std::string profileURL = "https://tactics.tools/player/na/" + fillSpaces(name) + "/" + player.getFullName()[1] + "/";
	std::string matchResultURL = profileURL + player.getCurrMatchID();
	//std::string augmentList = augListStr(player);
	std::string playerTier = player.getPlayerRank().first;
	dpp::embed outEmbed = dpp::embed()
		.set_color(data.getRankColor().at(playerTier))
		.set_title(data.getPlacementData().at(player.getMatchInfo().placement) + " PLACE")
		.set_url(matchResultURL)
		.set_author(name + "'s match result", profileURL, "")
		.set_thumbnail("https://ddragon.leagueoflegends.com/cdn/13.24.1/img/tft-tactician/Tooltip_TFTAvatar_BubbleTea_BubbleTea_Tier1.LL_TFTAvatar_BubbleTea.png")
		.add_field(
			data.getRankData().at(playerTier)[1] + " " + playerTier + " " + player.getPlayerRank().second + " (" + std::to_string(player.getPlayerLP().second) + " LP)" ,
			"\n"
			"Duration: " + std::to_string(player.getTime()[0]) + ":" + std::to_string(player.getTime()[1]) + "\n"
			"Level: " + std::to_string(player.getMatchInfo().level) + "\n"
			"Gold Left: " + std::to_string(player.getMatchInfo().goldLeft) + "\n"
			"Board Value: " + std::to_string(player.getMatchInfo().boardValue),
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
		.set_thumbnail(data.getRankData().at(playerTier))
		.add_field(
			name + " has promoted to " + playerTier,
			"",
			false
		);

	return promoEmbed;
};