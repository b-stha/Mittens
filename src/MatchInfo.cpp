#include "MatchInfo.h"

int MatchInfo::calcBoardValue() {
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