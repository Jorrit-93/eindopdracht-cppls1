#pragma once
#include "i_turn_view.h"

class InBattleView : ITurnView
{
public:
	void printBattleOutput(int hp, Array<int>* pirate_hp);
	void printAttackOutput(int damage, Array<int>* pirate_damage);
	void printFleeOutput(bool fled);
	void printSurrenderOutput();
};
