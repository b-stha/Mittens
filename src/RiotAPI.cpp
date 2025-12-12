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
	botCluster.request(matchIDurl, dpp::m_get, [&player, next, matchIDurl](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"Match ID HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			std::cout << "url: " << matchIDurl << std::endl;
			std::cout << "body: " << http.body << std::endl;
			return;
		}

		json matchIDJson;
		try {
			std::cout << "Request URL: " << matchIDurl << "\n";
			std::cout << "HTTP Status: " << http.status << "\n";
			std::cout << "HTTP Body: " << http.body << "\n";
			matchIDJson = json::parse(http.body);
		} catch (const json::parse_error& e) {
			std::cerr << "JSON parse error for url:" << matchIDurl << " - " << e.what() << "\nbody: " << http.body << std::endl;
			return;
		}

		if (matchIDJson.empty()) {
			std::cout << "No matches found for player with PUUID: " + player.getPUUID() << std::endl;
			return;
		}
		if (matchIDJson[0].get<std::string>() == player.getCurrMatchID()) {
			return;
		}
		
		player.setPrevMatch(player.getCurrMatchID());
		player.setCurrMatch(matchIDJson[0].get<std::string>());
		if (next) {
			next();
		}
	});
}

void Riot::fetchInfo(Player& player, std::function<void()> next) {
	std::string infoURL = "https://americas.api.riotgames.com/tft/match/v1/matches/" + player.getCurrMatchID() + "?api_key=" + apiKey;
    botCluster.request(infoURL, dpp::m_get, [&player, next, infoURL](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"Match info HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			std::cout << "url: " << infoURL << std::endl;
			std::cout << "body: " << http.body << std::endl;
			return;
		}

		json matchJson;
		try {
			std::cout << "Request URL: " << infoURL << "\n";
			std::cout << "HTTP Status: " << http.status << "\n";
			std::cout << "HTTP Body: " << http.body << "\n";
			matchJson = json::parse(http.body);
		} catch (const json::parse_error& e) {
			std::cerr << "JSON parse error for url:" << infoURL << " - " << e.what() << "\nbody: " << http.body << std::endl;
			return;
		}

		json allInfo = matchJson["info"];
		MatchInfo matchInfo;
		for (const json participant : allInfo["participants"]) {
			if (player.getPUUID() == participant["puuid"].get<std::string>()) {
				matchInfo = participant.get<MatchInfo>();
				double totalSeconds = participant["time_eliminated"].get<double>();
				matchInfo.gameLenMin = static_cast<int>(totalSeconds / 60);
				matchInfo.gameLenSec = static_cast<int>(totalSeconds) % 60;
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
	botCluster.request(nameURL, dpp::m_get, [&player, nameURL](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"Player name HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			std::cout << "url: " << nameURL << std::endl;
			std::cout << "body: " << http.body << std::endl;
			return;
		}

		json nameJson;
		try {
			std::cout << "Request URL: " << nameURL << "\n";
			std::cout << "HTTP Status: " << http.status << "\n";
			std::cout << "HTTP Body: " << http.body << "\n";
			nameJson = json::parse(http.body);
		} catch (const json::parse_error& e) {
			std::cerr << "JSON parse error for url:" << nameURL << " - " << e.what() << "\nbody: " << http.body << std::endl;
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
    botCluster.request(idURL, dpp::m_get, [name, tag, next, idURL](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"PUUID HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			std::cout << "url: " << idURL << std::endl;
			std::cout << "body: " << http.body << std::endl;
			return;
		}

		json idJson;
		try {
			std::cout << "Request URL: " << idURL << "\n";
			std::cout << "HTTP Status: " << http.status << "\n";
			std::cout << "HTTP Body: " << http.body << "\n";
			idJson = json::parse(http.body);
		} catch (const json::parse_error& e) {
			std::cerr << "JSON parse error for url:" << idURL << " - " << e.what() << "\nbody: " << http.body << std::endl;
			return;
		}

		std::string puuid = idJson["puuid"].get<std::string>();
		std::cout << "puuid: " << puuid << std::endl;
		if (next) {
			next(puuid);
		}
	});
}

void Riot::fetchSummonerID(Player& player) {
	std::string summonerURL = "https://na1.api.riotgames.com/tft/summoner/v1/summoners/by-puuid/" + player.getPUUID() + "?api_key=" + apiKey;
	botCluster.request(summonerURL, dpp::m_get, [&player, summonerURL](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"Summoner ID HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			std::cout << "url: " << summonerURL << std::endl;
			std::cout << "body: " << http.body << std::endl;
			return;
		}

		json summonerJson;
		try {
			
			std::cout << "Request URL: " << summonerURL << "\n";
			std::cout << "HTTP Status: " << http.status << "\n";
			std::cout << "HTTP Body: " << http.body << "\n";
			summonerJson = json::parse(http.body);
		} catch (const json::parse_error& e) {
			std::cerr << "JSON parse error for url:" << summonerURL << " - " << e.what() << "\nbody: " << http.body << std::endl;
			return;
		}

		std::string summonerID = summonerJson["id"].get<std::string>();
		player.setSummonerID(summonerID);
	});
}

void Riot::fetchLeague(Player& player, std::function<void()> next) {
	std::string leagueURL = "https://na1.api.riotgames.com/tft/league/v1/by-puuid/" + player.getPUUID() + "?api_key=" + apiKey;
	botCluster.request(leagueURL, dpp::m_get, [&player, next, leagueURL](const dpp::http_request_completion_t& http) {
		if (http.status != 200) {
			std::cout <<"League HTTP request failed with status: " + std::to_string(http.status) << std::endl;
			std::cout << "url: " << leagueURL << std::endl;
			std::cout << "body: " << http.body << std::endl;
			return;
		}

		json leagueJson;
		try {
			std::cout << "Request URL: " << leagueURL << "\n";
			std::cout << "HTTP Status: " << http.status << "\n";
			std::cout << "HTTP Body: " << http.body << "\n";
			leagueJson = json::parse(http.body);
			std::cout << leagueJson.dump(2) << std::endl;
		} catch (const json::parse_error& e) {
			std::cerr << "JSON parse error for url:" << leagueURL << " - " << e.what() << "\nbody: " << http.body << std::endl;
			return;
		}

		if (leagueJson.empty()) {
			player.updateLP(0);
			player.updateTier("UNRANKED", "");
		}
		else {
			player.updateLP(leagueJson[0]["leaguePoints"].get<int>());
			player.updateTier(leagueJson[0]["tier"].get<std::string>(), leagueJson[0]["rank"].get<std::string>());
		}

		if (next) {
			next();
		}
	});
}