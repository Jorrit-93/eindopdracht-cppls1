#pragma once
#include "turn.h"

class InHarbor : public Turn
{
public:
	InHarbor();
	~InHarbor() override;

	void nextTurn() override;
};
