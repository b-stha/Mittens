#include "bot.h"

dpp::embed createResult(const Player& player) {
	std::string matchResultURL = player.getTTUrl() + "/" + player.getCurrMatch();
	std::string nameStr = player.getFullName()[0] + "#" + player.getFullName()[1];



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
			"Champions",
			""
		);

	return 
};
