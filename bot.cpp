#include "bot.h"

std::string augListStr(const Player& player) {
	std::string augListOutput = "";

	if (player.myMatchInfo.augments.empty()) {
		return "None";
	}

	for (const auto& augment : player.myMatchInfo.augments) {
		augListOutput += augmentData.at(augment)[1] + " " + augmentData.at(augment)[0] + "\n";
	}
	return augListOutput;
}


void unitListStr(const Player& player, dpp::embed& embedObj) {
	for (const auto& unit : player.myMatchInfo.units) {
		std::string unitName = unitData.at(unit.characterID)[0];
		unitName = setStrWidth(unitName, 9);

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
	std::string matchResultURL = player.getTTUrl() + "/" + player.getCurrMatch();
	std::string nameStr = player.getFullName()[0] + "#" + player.getFullName()[1];
	std::string augmentList = augListStr(player);
	dpp::embed outEmbed = dpp::embed()
		.set_color(dpp::colors::sti_blue)
		.set_title("Match result")
		.set_url(matchResultURL)
		.set_thumbnail("https://raw.communitydragon.org/pbe/game/assets/ux/tft/outofgame/battlepass/rewards/tactician_serenitysprite_tft_set11b.png")
		.set_description(
			"Duration: " + std::to_string(player.getTime()[0]) + ":" + std::to_string(player.getTime()[1]) + "\n"
			"Level: " + std::to_string(player.myMatchInfo.level) + "\n"
			"Placement: " + std::to_string(player.myMatchInfo.placement) + "\n"
			"Gold Left: " + std::to_string(player.myMatchInfo.goldLeft)
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
