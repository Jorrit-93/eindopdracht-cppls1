#pragma once
#include "i_turn.h"

class OnSea : public ITurn
{
public:
	OnSea();
	~OnSea() override;
	
	void nextTurn() override;
};
