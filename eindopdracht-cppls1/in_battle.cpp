#include "in_battle.h"

InBattle::InBattle(Game* game)
	: game(game)
{
	
}

InBattle::~InBattle()
{
	delete view;
}
