#pragma once
#include "turn.h"

class OnSea : public Turn
{
public:
	OnSea();
	~OnSea() override;
	
	void nextTurn() override;
};
