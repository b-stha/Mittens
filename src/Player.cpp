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

void Player::updateRankedLP(const int newLP) {
	std::lock_guard<std::mutex> lock(playerMutex);
	leagues[0].prevLP = leagues[0].currLP;
	leagues[0].currLP = newLP;
}

void Player::updateDoubleUpLP(const int newLP) {
	std::lock_guard<std::mutex> lock(playerMutex);
	leagues[1].prevLP = leagues[1].currLP;
	leagues[1].currLP = newLP;
}

void Player::updateRankedTier(const std::string newTier, const std::string newRank) {
	std::lock_guard<std::mutex> lock(playerMutex);
	leagues[0].prevTier = leagues[0].tier;
	leagues[0].tier = newTier;
	leagues[0].rank = newRank;
}

void Player::updateDoubleUpTier(const std::string newTier, const std::string newRank) {
	std::lock_guard<std::mutex> lock(playerMutex);
	leagues[1].prevTier = leagues[1].tier;
	leagues[1].tier = newTier;
	leagues[1].rank = newRank;
}

std::pair<std::string, std::string> Player::getRank() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return std::make_pair(leagues[0].tier, leagues[0].rank);
}

std::pair<std::string, std::string> Player::getDoubleUpRank() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return std::make_pair(leagues[1].tier, leagues[1].rank);
}

std::vector<League> Player::getAllRanks() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return leagues;
}

std::pair<int,int> Player::getRankedLP() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return std::make_pair(leagues[0].prevLP, leagues[0].currLP);
}

std::pair<int,int> Player::getDoubleUpLP() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return std::make_pair(leagues[1].prevLP, leagues[1].currLP);
}

std::string Player::getPrevRanked() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return leagues[0].prevTier;
}

std::string Player::getPrevDoubleUp() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return leagues[1].prevTier;
}

MatchInfo Player::getMatchInfo() const {
	std::lock_guard<std::mutex> lock(playerMutex);
	return matchInfo;
}

void Player::setMatchInfo(const MatchInfo& currMatch) {
	matchInfo = currMatch;
}