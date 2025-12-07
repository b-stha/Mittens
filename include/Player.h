#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <dpp/dpp.h>
#include "MatchInfo.h"

struct League {
	std::string tier;
	std::string prevTier;
	int prevLP = 0;
	int currLP = 0;
	std::string rank;
};

class Player {
public:
	Player(std::string inputPuuid);
	void setMatchInfo(const MatchInfo& info);
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
	std::pair<std::string, std::string> getPlayerRank() const;
	std::pair<int, int> getPlayerLP() const;
	void setPlayerRank(League inLeague);
	void updateLP();
	std::string getPrevTier() const;
	void setPrevTier(std::string tier);
	const MatchInfo& getMatchInfo() const;
private:
	MatchInfo matchInfo;
	dpp::snowflake channelID;
	std::string puuid;
	std::string prevMatchID = "";
	std::string currMatchID = "";
	std::string userName = "";
	std::string tagLine = "";
	std::string summonerID;
	League playerRank;
};

#endif