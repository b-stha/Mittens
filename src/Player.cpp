#include "Player.h"
#include "helpers.h"
#include <iostream>
#include <fstream>
#include <cmath>

Player::Player(std::string inputPuuid) {
	puuid = inputPuuid;
}

void Player::setMatchInfo(const Info& info) {
	for (const auto& player : info.playerInfoList) {
		if (puuid == player.puuid) {
			myMatchInfo = player;
			myMatchInfo.boardValue = myMatchInfo.calcBoardValue();
			double totGameLength = info.gameLength / 60.0;
			gameLenSec = modf(totGameLength, &gameLenMin) * 60;
			return;
		}
	}
	throw std::runtime_error("Participant with the specified PUUID not found");
};

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

void Player::addTrait(const Trait& trait) {
	myMatchInfo.traits.push_back(trait);
}


int PlayerMatchInfo::calcBoardValue() {
	int boardValue = 0;
	int unitCount;
	for (auto unit : units) {
		if (unit.tier > 1) {
			unitCount = 3 * (unit.tier - 1);
		}
		else {
			unitCount = 1;
		}

		switch (unit.rarity)
		{
		case 0:
			boardValue += 1 * unitCount;
			break;
		case 1:
			boardValue += 2 * unitCount;
			break;
		case 2:
			boardValue += 3 * unitCount;
			break;
		case 4:
			boardValue += 4 * unitCount;
			break;
		case 6:
			boardValue += 5 * unitCount;
			break;
		case 8:
			boardValue += 6 * unitCount;
			break;
		}
	}
	return boardValue;
}
