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

void Riot::setName(Player& player) {
	std::string nameURL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-puuid/" + player.getPUUID() + "?api_key=" + apiKey;
	botCluster->request(nameURL, dpp::m_get, [&player](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json nameJson = json::parse(http.body);
		if (nameJson.empty()) {
			std::cout << "No name info found for player with PUUID: " + player.getPUUID() << std::endl;
			return;
		}

		std::string name = nameJson["gameName"].get<std::string>();
		std::string tag = nameJson["tagLine"].get<std::string>();
		player.setNameTag(name, tag);
	});
}

void Riot::fetchPUUID(const std::string& name, const std::string& tag, std::function<void(const std::string&)> next) {
    std::string fixedName = fillSpaces(name);
	std::string idURL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-riot-id/" + fixedName + "/" + tag + "?api_key=" + apiKey;
    botCluster->request(idURL, dpp::m_get, [name, tag, next](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json idJson = json::parse(http.body);
		if (idJson.empty()) {
			std::cout << "No PUUID found for player: " + name + "#" + tag << std::endl;
			return;
		}
		std::string puuid = idJson["puuid"].get<std::string>();
		if (next) {
			next(puuid);
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