#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <dpp/dpp.h>
#include "traits.h"

struct Companion {
    std::string contentID;
    int itemID;
    int skinID;
    std::string species;
};

struct Unit {
	std::string characterID;
	std::vector<std::string> items;
	int rarity = 0;
	int tier = 0;
};

struct PlayerMatchInfo {
	//std::vector<std::string> augments;
	std::vector<Trait> traits;
	std::vector<Unit> units;
	int goldLeft = 0;
	int level = 0;
	int placement = 0;
	std::string puuid;
	int boardValue;
    Companion tacticianInfo;
};

struct Info {
	double gameLength;
	std::vector<PlayerMatchInfo> playerInfoList;
};

struct League {
	std::string tier;
	std::string rank;
	int prevLP = 0;
	int currLP = 0;
};

class Player {
public:
	Player(std::string inputPuuid);
	void setMatchInfo(const Info& info);
	void setNameTag(std::string inputName, std::string inputTag);
	void setprevMatch(std::string matchID);
	void setCurrMatch(std::string matchID);
	std::string getCurrMatch() const;
	std::string getPUUID() const;
	std::vector<std::string> getFullName() const;
	std::vector<int> getTime() const;
	void setChannelID(dpp::snowflake inputChannelID);
	dpp::snowflake getChannelID();
	void setSummonerID(std::string summonerID);
	std::string getSummonerID();
	std::pair<std::string, std::string> getPlayerRank();
	std::pair<int, int> getPlayerLP() const;
	void setPlayerRank(League inLeague);
	void updateLP();
	PlayerMatchInfo myMatchInfo;
private:
	dpp::snowflake channelID;
	double gameLenMin = 0;
	double gameLenSec = 0;
	std::string puuid;
	std::string prevMatchID = "";
	std::string currMatchID = "";
	std::string userName = "";
	std::string tagLine = "";
	std::string summonerID;
	League playerRank;
};

#endif