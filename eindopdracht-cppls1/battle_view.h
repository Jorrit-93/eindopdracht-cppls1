#pragma once
#include "turn_view.h"

class BattleView : public TurnView
{
public:
	void printBattleOutput(int hp, Array<int>* pirate_hp);
	void printAttackOutput(int damage, Array<int>* pirate_damage);
	void printFleeOutput(bool fled);
	void printSurrenderOutput();
};
