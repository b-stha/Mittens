#include "RiotAPI.h"
#include "Player.h"
#include <nlohmann/json.hpp>
#include <string>
#include "helpers.h"

using json = nlohmann::json;

Riot::Riot(dpp::cluster& bot, const std::string& apiKey)
	: botCluster(bot), apiKey(apiKey)
	{}

void Riot::fetchMatchID(Player& player, std::function<void()> next) {
	std::string matchIDurl = "https://americas.api.riotgames.com/tft/match/v1/matches/by-puuid/" + player.getPUUID() + "/ids?count=1&api_key=" + apiKey;
	botCluster.request(matchIDurl, dpp::m_get, [&player, next](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json matchIDjson = json::parse(http.body);
		if (matchIDjson.empty()) {
			std::cout << "No matches found for player with PUUID: " + player.getPUUID() << std::endl;
			return;
		}
		if (matchIDjson[0].get<std::string>() == player.getCurrMatchID()) {
			return;
		}
		
		player.setPrevMatch(player.getCurrMatchID());
		player.setCurrMatch(matchIDjson[0].get<std::string>());
		if (next) {
			next();
		}
	});
}

void Riot::fetchInfo(Player& player, std::function<void()> next) {
	std::string infoURL = "https://americas.api.riotgames.com/tft/match/v1/matches/" + player.getCurrMatchID() + "?api_key=" + apiKey;
    botCluster.request(infoURL, dpp::m_get, [&player, next](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json matchJson = json::parse(http.body);
		if (matchJson.empty()) {
			std::cout << "No match info found for match ID: " + player.getCurrMatchID() << std::endl;
			return;
		}

		json allInfo = matchJson["info"];
		MatchInfo matchInfo;
		for (const json participant : allInfo["participants"]) {
			if (player.getPUUID() == participant["puuid"].get<std::string>()) {
				double totGameLength = allInfo["game_length"].get<double>() / 60.0;
				matchInfo.gameLenSec = modf(totGameLength, &matchInfo.gameLenMin) * 60;
				matchInfo = participant.get<MatchInfo>();
				matchInfo.boardValue = matchInfo.calcBoardValue();
			}
		}

		player.setMatchInfo(matchInfo);
		if (next) {
			next();
		}
	});
};

void Riot::setName(Player& player) {
	std::string nameURL = "https://americas.api.riotgames.com/riot/account/v1/accounts/by-puuid/" + player.getPUUID() + "?api_key=" + apiKey;
	botCluster.request(nameURL, dpp::m_get, [&player](const dpp::http_request_completion_t& http) {
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
    botCluster.request(idURL, dpp::m_get, [name, tag, next](const dpp::http_request_completion_t& http) {
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
	});
}

void Riot::fetchSummonerID(Player& player) {
	std::string summonerURL = "https://na1.api.riotgames.com/tft/summoner/v1/summoners/by-puuid/" + player.getPUUID() + "?api_key=" + apiKey;
	botCluster.request(summonerURL, dpp::m_get, [&player](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json summonerJson = json::parse(http.body);
		if (summonerJson.empty()) {
			std::cout << "No summoner info found for player with PUUID: " + player.getPUUID() << std::endl;
			return;
		}

		std::string summonerID = summonerJson["id"].get<std::string>();
		player.setSummonerID(summonerID);
	});
}

void Riot::fetchLeague(Player& player, std::function<void()> next) {
	std::string leagueURL = "https://na1.api.riotgames.com/tft/league/v1/entries/by-summoner/" + player.getSummonerID() + "?api_key=" + apiKey;
	botCluster.request(leagueURL, dpp::m_get, [&player, next](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			return;
		}
		json leagueJson = json::parse(http.body);
		if (leagueJson.empty()) {
			std::cout << "No league info found for summoner ID: " + player.getSummonerID() << std::endl;
			return;
		}

		League playerLeague;
		playerLeague.prevLP = playerLeague.currLP;
		playerLeague.prevTier = playerLeague.tier;
		playerLeague.rank = leagueJson[0]["rank"].get<std::string>();
		playerLeague.currLP = leagueJson[0]["leaguePoints"].get<int>();
		playerLeague.tier = leagueJson[0]["rank"].get<std::string>();
		player.setPlayerRank(playerLeague);

		if (next) {
			next();
		}
	});
}