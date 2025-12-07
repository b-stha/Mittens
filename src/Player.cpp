#include "Player.h"
#include "helpers.h"
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

std::string Player::getCurrMatch() const {
	return currMatchID;
};

std::vector<std::string> Player::getFullName() const {
	std::vector<std::string> nameVec{ userName, tagLine };
	return nameVec;
}

std::vector<int> Player::getTime() const {
    std::cout << gameLenMin << ":" << gameLenSec << std::endl;
	int min = static_cast<int>(gameLenMin);
	int sec = static_cast<int>(gameLenSec);
	std::vector<int> timeVec{ min, sec };
	return timeVec;
}

dpp::snowflake Player::getChannelID() {
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

void Player::setPlayerRank(League inLeague) {
	playerRank = inLeague;
}

void Player::updateLP() {
	prevLP = playerRank.currLP;
}

std::pair<std::string, std::string> Player::getPlayerRank() const {
	return std::make_pair(playerRank.tier, playerRank.rank);
}

std::pair<int,int> Player::getPlayerLP() const {
	return std::make_pair(prevLP, playerRank.currLP);
}

std::string Player::getPrevTier() const {
	return prevTier;
}

void Player::setPrevTier(std::string tier) {
	prevTier = tier;
}

const MatchInfo& Player::getMatchInfo() const {
	return matchInfo;
}
