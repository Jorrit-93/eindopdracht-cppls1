#pragma once
#include "turn_view.h"
#include "game.h"

class Turn
{
protected:
	Game* game;
	TurnView* view;
	int distance;
	
public:
	virtual ~Turn() = default;
	
protected:
	virtual void nextTurn() = 0;
};
