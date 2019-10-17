#pragma once
#include "turn.h"

class InBattle : public Turn
{
public:
	InBattle();
	~InBattle() override;

	void nextTurn() override;
};
