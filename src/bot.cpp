#include "bot.h"


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

void unitListStr(const Player& player, dpp::embed& embedObj) {
	for (const auto& unit : player.myMatchInfo.units) {
		std::string apiName = unit.characterID;

		std::transform(apiName.begin(), apiName.end(), apiName.begin(), 
          [](unsigned char c){ return std::tolower(c); });

		std::string unitName = unitData.at(apiName)[0];
		unitName = setStrWidth(unitName, 10);

		std::string unitIconName = unitData.at(apiName)[1] + " " + unitName;
		std::string unitItems = itemListStr(unit);
		embedObj.add_field(
			"", 
			starCount(unit.tier) + "\n" + 
			unitIconName + "\n" +
			unitItems + "\n",
			true);
	};
};

void traitListStr(const Player& player, dpp::embed& embedObj) {
	for (const auto& trait : player.myMatchInfo.traits) {
		if (trait.style != 0) {
			std::string apiName = trait.apiName;

			std::transform(apiName.begin(), apiName.end(), apiName.begin(), 
			[](unsigned char c){ return std::tolower(c); });

			const TraitTemplate& traitRef = traitData.at(apiName);

			std::string traitName = traitRef.name;
			int currBreakpoint = traitRef.breakpoints[trait.level-1];

			traitName = setStrWidth(traitName, 10);
			std::string traitIcon = traitRef.styles.at(trait.style);
			embedObj.add_field(
				"", 
				traitIcon + " " + std::to_string(trait.numUnits) + "/" + std::to_string(currBreakpoint) + " " + traitName,
				true);
		}
	};
};

dpp::embed createResult(const Player& player) {
    std::string name = player.getFullName()[0];
	std::string profileURL = "https://tactics.tools/player/na/" + fillSpaces(name) + "/" + player.getFullName()[1] + "/";
	std::string matchResultURL = profileURL + player.getCurrMatch();
	//std::string augmentList = augListStr(player);
	std::string playerTier = player.getPlayerRank().first;
	dpp::embed outEmbed = dpp::embed()
		.set_color(rankColor.at(playerTier))
		.set_title(placementData.at(player.myMatchInfo.placement) + " PLACE")
		.set_url(matchResultURL)
		.set_author(name + "'s match result", profileURL, "")
		.set_thumbnail("https://ddragon.leagueoflegends.com/cdn/13.24.1/img/tft-tactician/Tooltip_TFTAvatar_BubbleTea_BubbleTea_Tier1.LL_TFTAvatar_BubbleTea.png")
		.add_field(
			rankData.at(playerTier)[1] + " " + playerTier + " " + player.getPlayerRank().second + " (" + std::to_string(player.getPlayerLP().second) + " LP)" ,
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
	traitListStr(player, outEmbed);
	outEmbed
		.add_field(
			"Units",
			"",
			false
		);
	unitListStr(player, outEmbed);

	return outEmbed;
};

dpp::embed createPromoMsg(const Player& player) {
	std::string playerTier = player.getPlayerRank().first;
	std::string name = player.getFullName()[0];
	dpp::embed promoEmbed = dpp::embed()
		.set_color(rankColor.at(playerTier))
		.set_title("PROMOTION")
		.set_thumbnail(rankData.at(playerTier)[0])
		.add_field(
			name + " has promoted to " + playerTier,
			"",
			false
		);

	return promoEmbed;
};