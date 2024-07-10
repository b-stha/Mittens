#include "Player.h"
#include "helpers.h"

Player::Player(std::string inputPuuid) {
	puuid = inputPuuid;
}

void Player::setMatchInfo(const Info& info) {
	for (const auto& player : info.playerInfoList) {
		if (puuid == player.puuid) {
			myMatchInfo = player;
			myMatchInfo.boardValue = calcBoardValue(myMatchInfo);
			double totGameLength = info.gameLength / 60.0;
			gameLenSec = modf(totGameLength, &gameLenMin);
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

void Player::setprevMatch(std::string matchID) {
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
	int min = static_cast<int>(gameLenMin);
	int sec = static_cast<int>(gameLenSec);
	std::vector<int> timeVec{ min, sec };
	return timeVec;
}

dpp::snowflake Player::getChannelID() {
	return channelID;
}

void Player::setSnowflake(dpp::snowflake inputChannelID) {
	channelID = inputChannelID;
}