#pragma once
#include "i_turn_view.h"

class ITurn
{
protected:
	int distance;
	ITurnView* view;
	
public:
	virtual ~ITurn() = default;
	
protected:
	virtual void nextTurn() = 0;
};
