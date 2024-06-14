#include "bot.h"

std::string operator * (std::string a, unsigned int b) {
	std::string output = "";
	while (b--) {
		output += a;
	}
	return output;
}


std::string itemListStr(const Unit& unit) {
	std::string itemListOutput = "";
	std::string emptyItem = "<:transparent:1250910469330567292> ";
	if (unit.items.empty()) {
		itemListOutput += (emptyItem * 3);
	}
	else {
		for (const auto& item : unit.items) {
			itemListOutput += itemData.at(item) + " ";
		}
	}
	return itemListOutput;
}

std::string augListStr(const Player& player) {
	std::string augListOutput = "";

	if (player.myMatchInfo.augments.empty()) {
		return "None";
	}

	for (const auto& augment : player.myMatchInfo.augments) {
		augListOutput += "\n";
	}
	return augListOutput;
}

std::string starCount(const int& tier) {
	std::string star = ":star:";
	return (star * tier);
};

void unitListStr(const Player& player, dpp::embed& embedObj) {
	for (const auto& unit : player.myMatchInfo.units) {
		std::string unitIconName = unitData.at(unit.characterID)[1] + " " + unitData.at(unit.characterID)[0];
		std::string unitItems = itemListStr(unit);
		embedObj.add_field(
			"", 
			starCount(unit.tier) + "\n" + 
			unitIconName + "\n" +
			unitItems,
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
		.set_description("Duration: " + std::to_string(player.getTime()[0]) + ":" + std::to_string(player.getTime()[1]))
		.add_field(
			"Augments",
			"<:epoch:1250660808342634546> Epoch\n"
			"<:crest_storyweaver:1250660995844669551> Storyweaver Crest \n"
			"<:pandora3:1250661046910455858> Pandora's Box III"
		)
		.add_field(
			"Units",
			"",
			false
		);
	unitListStr(player, outEmbed);

	return outEmbed;
};