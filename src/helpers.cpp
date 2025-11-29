#include "helpers.h"
#include <sstream>

std::string operator * (std::string a, unsigned int b) {
	std::string output = "";
	while (b--) {
		output += a;
	}
	return output;
}

std::string setStrWidth(const std::string& str, int len) {
	std::string result = str;
	int spaces_to_add = len - str.length();
	for (int i = 0; i < spaces_to_add; ++i) {
		result += " ";
	}
	return result;
}

std::string starCount(const int& tier) {
	std::string star = ":star:";
	return (star * tier);
};

std::vector<std::string> split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

bool notPlayerExists(const std::vector<std::unique_ptr<Player>>& players, const std::string& puuid) {
	return std::none_of(players.begin(), players.end(),
		[&puuid](const std::unique_ptr<Player>& player) {
			return player->getPUUID() == puuid;
		});
}

std::string fillSpaces(std::string input) {
    std::string fillStr = "%20";
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            input.erase(i,1);
            input.insert(i, fillStr);
        }
    }
    return input;
}

int subtractLP(const Player& player) {
	if (player.getPlayerLP().first == 0) {
		return (player.getPlayerLP().second - 100);
	}

	return (player.getPlayerLP().second - player.getPlayerLP().first);
}

bool sortByStyle(const Trait& t1, const Trait& t2) {
	return t1.style > t2.style;
}