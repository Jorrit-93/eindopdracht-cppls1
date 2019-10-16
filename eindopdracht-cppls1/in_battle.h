#pragma once
#include "i_turn.h"

class InBattle : public ITurn
{
public:
	InBattle();
	~InBattle() override;

	void nextTurn() override;
};
