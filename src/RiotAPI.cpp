#include "RiotAPI.h"
#include "parsejson.h"
#include "helpers.h"

void Riot::fetchMatchID(Player& player, std::function<void()> next) {
	std::string matchIDurl = "https://americas.api.riotgames.com/tft/match/v1/matches/by-puuid/" + player.getPUUID() + "/ids?count=1&api_key=" + apiKey;
	botCluster->request(matchIDurl, dpp::m_get, [&player, next](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json matchIDjson = json::parse(http.body);
		if (matchIDjson.empty()) {
			std::cout << "No matches found for player with PUUID: " + player.getPUUID() << std::endl;
			return;
		}
		if (matchIDjson[0].get<std::string>() == player.getCurrMatch()) {
			return;
		}
		
		player.setPrevMatch(player.getCurrMatch());
		player.setCurrMatch(matchIDjson[0].get<std::string>());
		if (next) {
			next();
	}
	});
}

void Riot::fetchInfo(Player& player, std::function<void()> next) {
	std::string infoURL = "https://americas.api.riotgames.com/tft/match/v1/matches/" + player.getCurrMatch() + "?api_key=" + apiKey;
    botCluster->request(infoURL, dpp::m_get, [&player, next](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json infoJson = json::parse(http.body);
		if (infoJson.empty()) {
			std::cout << "No match info found for match ID: " + player.getCurrMatch() << std::endl;
			return;
		}

		Info matchInfo = infoJson.get<Info>();
		player.setMatchInfo(matchInfo);
		if (next) {
			next();
		}
	});
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

	throw std::runtime_error("Error finding player...");
}

std::string fetchSummonerID(const std::string& puuid, const std::string& apiKey) {
	std::string summonerURL = "https://na1.api.riotgames.com/tft/summoner/v1/summoners/by-puuid/" + puuid + "?api_key=" + apiKey;

	json summonerJSON = makeReq(summonerURL, 10, 1000);

	if (!summonerJSON.empty()) {
		return summonerJSON["id"].get<std::string>();
	}

	throw std::runtime_error("Error finding summoner ID...");
}

League fetchLeague(Player& player, const std::string& apiKey) {
	std::string leagueURL = "https://na1.api.riotgames.com/tft/league/v1/entries/by-summoner/" + player.getSummonerID() + "?api_key=" + apiKey;

	json leagueJSON = makeReq(leagueURL, 10, 1000);

	if (!leagueJSON.empty()) {
		return leagueJSON[0].get<League>();
	}

	throw std::runtime_error("No ranked information...");
}