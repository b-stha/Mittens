#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <dpp/dpp.h>

struct Unit {
	std::string characterID;
	std::vector<std::string> items;
	int rarity = 0;
	int tier = 0;
};

struct TraitTemplate {
	const std::string name;
	const std::vector<int> breakpoints;
	const std::unordered_map<int, std::string> styles;

	TraitTemplate(const std::string& traitName, 
                  const std::vector<int>& bPoints,
                  const std::unordered_map<int, std::string>& sIcons)
        : name(traitName), breakpoints(bPoints), styles(sIcons) {}
};

struct Trait {
	std::string apiName;
	int level;
	int style;
	int numUnits;
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
	int companionID;
};

struct Info {
	double gameLength;
	std::vector<PlayerMatchInfo> playerInfoList;
};

struct League {
	std::string tier;
	std::string rank;
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
	std::string getSummonerID() const;
	std::pair<std::string, std::string> getPlayerRank() const;
	std::pair<int, int> getPlayerLP() const;
	void setPlayerRank(League inLeague);
	void updateLP();
	std::string getPrevTier() const;
	void setPrevTier(std::string tier);
	void addTrait(const Trait& trait);	
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
	int prevLP = 0;
	std::string prevTier;
};

#endif