#pragma once
#include "turn_view.h"

class IShip;

class BattleView : public TurnView
{
public:
	void printBattleOutput(IShip& pirate_ship) const;
};
