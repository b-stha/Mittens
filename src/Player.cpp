#include "Player.h"
#include <iostream>
#include <fstream>
#include <cmath>

Player::Player(std::string inputPuuid) {
	puuid = inputPuuid;
}

std::string Player::getPUUID() const {
	return puuid;
};

void Player::setNameTag(std::string inputName, std::string inputTag) {
	userName = inputName;
	tagLine = inputTag;
};

void Player::setPrevMatch(std::string matchID) {
	prevMatchID = matchID;
};

void Player::setCurrMatch(std::string matchID) {
	currMatchID = matchID;
};

std::string Player::getCurrMatchID() const {
	return currMatchID;
};

std::vector<std::string> Player::getFullName() const {
	std::vector<std::string> nameVec{ userName, tagLine };
	return nameVec;
}

std::vector<int> Player::getTime() const {
    std::cout << matchInfo.gameLenMin << ":" << matchInfo.gameLenSec << std::endl;
	int min = static_cast<int>(matchInfo.gameLenMin);
	int sec = static_cast<int>(matchInfo.gameLenSec);
	std::vector<int> timeVec{ min, sec };
	return timeVec;
}

dpp::snowflake Player::getChannelID() const {
	return channelID;
}

void Player::setChannelID(dpp::snowflake inputChannelID) {
	channelID = inputChannelID;
}

void Player::setSummonerID(std::string input) {
	summonerID = input;
}

std::string Player::getSummonerID() const {
	return summonerID;
}

void Player::setPlayerLeague(const League& inLeague) {
	playerRank = inLeague;
}

void Player::updateLP(const int newLP) {
	playerRank.prevLP = playerRank.currLP;
	playerRank.currLP = newLP;
}

void Player::updateTier(const std::string newTier, const std::string newRank) {
	playerRank.prevTier = playerRank.tier;
	playerRank.tier = newTier;
	playerRank.rank = newRank;
}

std::pair<std::string, std::string> Player::getPlayerRank() const {
	return std::make_pair(playerRank.tier, playerRank.rank);
}

std::string Player::getPrevRank() const {
	return playerRank.prevTier;
}

std::pair<int,int> Player::getPlayerLP() const {
	return std::make_pair(playerRank.prevLP, playerRank.currLP);
}
const MatchInfo& Player::getMatchInfo() const {
	return matchInfo;
}

void Player::setMatchInfo(const MatchInfo& currMatch) {
	matchInfo = currMatch;
}