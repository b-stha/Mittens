#include "bot.h"

std::string operator * (std::string a, unsigned int b) {
	std::string output = "";
	while (b--) {
		output += a;
	}
	return output;
}

std::string itemListStr(const Player& player) {
	std::string itemListOutput = "";
	for (const auto& unit : player.myMatchInfo.units) {
		if (unit.items.empty()) {
			itemListOutput += "\n";
		}
		else {
			for (const auto& item : unit.items) {
				itemListOutput += itemData.at(item) + " ";
			}
			itemListOutput += "\n";
		}
		itemListOutput += "\n";
	}
	return itemListOutput;
}

std::string starCount(const int& tier) {
	std::string star = ":star:";
	return (star * tier);
};

std::string unitListStr(const Player& player) {
	std::string unitListOutput = "";
	for (const auto& unit : player.myMatchInfo.units) {
		unitListOutput += unitData.at(unit.characterID)[1] + unitData.at(unit.characterID)[0] + "    \n";
		unitListOutput += starCount(unit.tier) + "\n\n";
	};
	return unitListOutput;
};

dpp::embed createResult(const Player& player) {
	std::string matchResultURL = player.getTTUrl() + "/" + player.getCurrMatch();
	std::string nameStr = player.getFullName()[0] + "#" + player.getFullName()[1];
	std::string unitList = unitListStr(player);
	std::string itemList = itemListStr(player);
	dpp::embed outEmbed = dpp::embed()
	.set_color(dpp::colors::sti_blue)
	.set_title("Match result")
	.set_url(matchResultURL)
	.set_author(nameStr, player.getTTUrl(), "https://raw.communitydragon.org/pbe/game/assets/ux/tft/outofgame/battlepass/rewards/tactician_serenitysprite_tft_set11b.png")
	.set_description("Duration: " + std::to_string(player.getTime()[0]) + ":" + std::to_string(player.getTime()[1]))
	.add_field(
		"Augments",
		"<:epoch:1250660808342634546> Epoch\n"
		"<:crest_storyweaver:1250660995844669551> Storyweaver Crest \n"
		"<:pandora3:1250661046910455858> Pandora's Box III"
	)
	.add_field(
		"Units",
		unitList,
		true
	)
	.add_field(
		"Items",
		itemList,
		true
	);

	return outEmbed;
};