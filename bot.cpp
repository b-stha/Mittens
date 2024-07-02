#include "bot.h"

/*void traitListStr(const PlayerMatchInfo& match, dpp::embed& embedObj) {
	for (const auto& trait : match.traits) {
		std::string traitOutput = "";
		switch (trait.style) {
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
		unitName = setStrWidth(unitName, 10);

		std::string unitIconName = unitData.at(unit.characterID)[1] + " " + unitName;
		std::string unitItems = itemListStr(unit);
		embedObj.add_field(
			"",
			starCount(unit.tier) + "\n" +
			unitIconName + "\n" +
			unitItems + "\n",
			true);
	};
};*/

std::string augListStr(const Player& player) {
	std::string augListOutput = "";

	if (player.myMatchInfo.augments.empty()) {
		return "None";
	}

	for (const auto& augment : player.myMatchInfo.augments) {
		augListOutput += augmentData.at(augment)[1] + " " + augmentData.at(augment)[0] + "\n";
	}
	return augListOutput;
};

void unitListStr(const Player& player, dpp::embed& embedObj) {
	for (const auto& unit : player.myMatchInfo.units) {
		std::string unitName = unitData.at(unit.characterID)[0];
		unitName = setStrWidth(unitName, 10);

		std::string unitIconName = unitData.at(unit.characterID)[1] + " " + unitName;
		std::string unitItems = itemListStr(unit);
		embedObj.add_field(
			"", 
			starCount(unit.tier) + "\n" + 
			unitIconName + "\n" +
			unitItems + "\n",
			true);
	};
};

dpp::embed createResult(const Player& player) {
	std::string matchResultURL = "https://tactics.tools/player/na/" + player.getFullName()[0] + "/" + player.getFullName()[1] + "/" + player.getCurrMatch();
	std::string nameStr = player.getFullName()[0] + "#" + player.getFullName()[1];
	std::string augmentList = augListStr(player);
	dpp::embed outEmbed = dpp::embed()
		.set_color(dpp::colors::sti_blue)
		.set_title(player.getFullName()[0] + "'s match result")
		.set_url(matchResultURL)
		.set_thumbnail("https://ddragon.leagueoflegends.com/cdn/13.24.1/img/tft-tactician/Tooltip_TFTAvatar_BubbleTea_BubbleTea_Tier1.LL_TFTAvatar_BubbleTea.png")
		.set_description(
			"Duration: " + std::to_string(player.getTime()[0]) + ":" + std::to_string(player.getTime()[1]) + "\n"
			"Level: " + std::to_string(player.myMatchInfo.level) + "\n"
			"Placement: " + std::to_string(player.myMatchInfo.placement) + "\n"
			"Gold Left: " + std::to_string(player.myMatchInfo.goldLeft) + "\n"
			"Board Value: " + std::to_string(player.myMatchInfo.boardValue)
		)
		.add_field(
			"Augments",
			augmentList,
			false
		)
		.add_field(
			"Units",
			"",
			false
		);
	unitListStr(player, outEmbed);

	return outEmbed;
};
