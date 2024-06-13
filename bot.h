#ifndef BOT_H
#define BOT_H

#include <dpp/dpp.h>
#include "Player.h"

dpp::embed createResult(const Player& player) {
	return dpp::embed()
		.set_color(dpp::colors::sti_blue)
		.set_title("Match result")
		.set_url(player.getTTUrl() + "/" + player.getCurrMatch())
		.set_author(player.getFullName()[0] + "#" + player.getFullName()[1], player.getTTUrl())
}

#endif
