#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <dpp/dpp.h>
#include "MatchInfo.h"
#include <unordered_set>
#include <mutex>

struct League {
	std::string tier = "UNRANKED";
	std::string prevTier = "UNRANKED";
	int prevLP = 0;
	int currLP = 0;
	std::string rank = "";
};

class Player {
public:
	Player(std::string inputPuuid);
	void setNameTag(std::string inputName, std::string inputTag);
	void setPrevMatch(std::string matchID);
	void setCurrMatch(std::string matchID);
	std::string getCurrMatchID() const;
	std::string getPUUID() const;
	std::vector<std::string> getFullName() const;
	std::vector<int> getTime() const;
	void setChannelID(dpp::snowflake inputChannelID);
	dpp::snowflake getChannelID() const;
	void setSummonerID(std::string summonerID);
	std::string getSummonerID() const;
	std::pair<std::string, std::string> getRank() const;
	std::pair<std::string, std::string> getDoubleUpRank() const;
	std::vector<League> getAllRanks() const;
	std::pair<int, int> getRankedLP() const;
	std::pair<int, int> getDoubleUpLP() const;
	std::string getPrevRanked() const;
	std::string getPrevDoubleUp() const;
	void updateRankedLP(const int newLP);
	void updateDoubleUpLP(const int newLP);
	void updateRankedTier(const std::string newTier, const std::string newRank);
	void updateDoubleUpTier(const std::string newTier, const std::string newRank);
	void setPlayerLeague(const std::vector<League>& inLeague);
	MatchInfo getMatchInfo() const;
	void setMatchInfo(const MatchInfo& currMatch);
	std::unordered_set<int> getAddedQueues() const;
	void addQueue(int queueID);
private:
	mutable std::mutex playerMutex;
	std::unordered_set<int> addedQueues;
	MatchInfo matchInfo;
	dpp::snowflake channelID;
	std::string puuid;
	std::string prevMatchID = "";
	std::string currMatchID = "";
	std::string userName = "";
	std::string tagLine = "";
	std::string summonerID;
	std::vector<League> leagues;
};

#endif