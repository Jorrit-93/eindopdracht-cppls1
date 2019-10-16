#pragma once
#include "i_turn.h"

class InHarbor : public ITurn
{
public:
	InHarbor();
	~InHarbor() override;

	void nextTurn() override;
};
