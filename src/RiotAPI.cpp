#include "RiotAPI.h"

std::string fetchMatchID(const Player& player, const std::string apiKey) {
	std::string matchIDurl = "https://americas.api.riotgames.com/tft/match/v1/matches/by-puuid/" + player.getPUUID() + "/ids?count=1&api_key=" + apiKey;
	json matchIDjson = makeReq(matchIDurl, 10, 1000);

	if (matchIDjson.is_array() && !matchIDjson.empty()) {
		return matchIDjson[0].get<std::string>();
	}
	else {
		throw std::runtime_error("Invalid JSON structure: expected non-empty array");
	}
};

Info fetchInfo(const std::string matchID, const std::string apiKey) {
	std::string infoURL = "https://americas.api.riotgames.com/tft/match/v1/matches/" + matchID + "?api_key=" + apiKey;
    std::cout << infoURL << std::endl;
	json infoJson = makeReq(infoURL, 10, 1000);

	return infoJson["info"].get<Info>();
};

void setName(Player& player, const std::string apiKey) {
	std::string nameURL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-puuid/" + player.getPUUID() + "?api_key=" + apiKey;
	json nameJson = makeReq(nameURL, 10, 1000);

	if (nameJson.is_array() && !nameJson.empty()) {
		player.setNameTag(nameJson[0].get<std::string>(), nameJson[1].get<std::string>());
	}
	else {
		throw std::runtime_error("Invalid JSON structure: expected non-empty array");
	}
}

std::string fetchPUUID(const std::string& name, const std::string& tag, const std::string& apiKey) {
    std::string fixedName = fillSpaces(name);
	std::string idURL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-riot-id/" + fixedName + "/" + tag + "?api_key=" + apiKey;
    std::cout << idURL << std::endl;
	json idJSON = makeReq(idURL, 10, 1000);

	if (!idJSON.empty()) {
		return idJSON["puuid"].get<std::string>();
	}
	else {
		throw std::runtime_error("Error finding player...");
	}

}
