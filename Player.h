#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

struct Trait {
	std::string name;
	int numUnits = 0;
	int style = 0;
	int tierCurrent = 0;
	int tierTotal = 0;
};

struct Unit {
	std::string characterID;
	std::vector<std::string> items;
	int rarity = 0;
	int tier = 0;
};

struct PlayerMatchInfo {
	std::vector<std::string> augments;
	std::vector<Trait> traits;
	std::vector<Unit> units;
	int goldLeft = 0;
	int level = 0;
	int placement = 0;
	std::string puuid;
};

struct Info {
	double gameLength;
	std::vector<PlayerMatchInfo> playerInfoList;
};


class Player {
	public:
		Player(std::string inputPuuid);
		void setMatchInfo(const Info& info);
		void setNameTag(std::string inputName, std::string inputTag);
		void setprevMatch(std::string matchID);
		void setCurrMatch(std::string matchID);
		std::string getTTUrl() const;
		std::string getCurrMatch() const;
		std::string getPUUID() const;
		std::vector<std::string> getFullName() const;
		std::vector<int> getTime() const;
		PlayerMatchInfo myMatchInfo;

	private:
		double gameLenMin = 0;
		double gameLenSec = 0;
		std::string puuid;
		std::string prevMatchID = "";
		std::string currMatchID = "";
		std::string userName = "";
		std::string tagLine = "";
		std::string tacticsToolsURL = "https://tactics.tools/player/na/" + userName + "/" + tagLine;
};

#endif