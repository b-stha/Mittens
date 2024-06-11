#include "RiotAPI.h"

std::string fetchMatchID(const Player& player, const std::string apiKey) {
	std::string matchIDurl = "https://americas.api.riotgames.com/tft/match/v1/matches/by-puuid/" + player.getPUUID() + "/ids?count=1&api_key=" + apiKey;
	cpr::Response matchIDr = cpr::Get(cpr::Url{ matchIDurl });
	json matchIDjson = parseJSON(matchIDr);

	if (matchIDjson.is_array() && !matchIDjson.empty()) {
		return matchIDjson[0].get<std::string>();
	}
	else {
		throw std::runtime_error("Invalid JSON structure: expected non-empty array");
	}
};

Info fetchInfo(const std::string matchID, const std::string apiKey) {
	std::string infoURL = "https://americas.api.riotgames.com/tft/match/v1/matches/" + matchID + "?api_key=" + apiKey;
	cpr::Response infoResponse = cpr::Get(cpr::Url{ infoURL });
	json infoJson = parseJSON(infoResponse);

	if (infoJson.is_array() && !infoJson.empty()) {
		return infoJson[0].get<Info>();
	}
	else {
		throw std::runtime_error("Invalid JSON structure: expected non-empty array");
	}
};

void setName(Player& player, const std::string apiKey) {
	std::string nameURL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-puuid/" + player.getPUUID() + "?api_key=" + apiKey;
	cpr::Response urlResponse = cpr::Get(cpr::Url{ nameURL });
	json nameJson = parseJSON(urlResponse);

	if (nameJson.is_array() && !nameJson.empty()) {
		player.setNameTag(nameJson[0].get<std::string>(), nameJson[1].get<std::string>());
	}
	else {
		throw std::runtime_error("Invalid JSON structure: expected non-empty array");
	}
}

