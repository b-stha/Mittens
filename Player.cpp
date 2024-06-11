#include "Player.h"

Player::Player(std::string inputPuuid) {
	puuid = inputPuuid;
}

void Player::setMatchInfo(const Info& info) {
	for (const auto& player : info.playerInfoList) {
		if (puuid == player.puuid) {
			myMatchInfo = player;
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

std::string Player::getTTUrl() const {
	return tacticsToolsURL;
};

std::string Player::getCurrMatch() const {
	return currMatchID;
};