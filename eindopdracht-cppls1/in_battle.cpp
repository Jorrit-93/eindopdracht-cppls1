#include "in_battle.h"
#include "game.h"

InBattle::InBattle(Game& game)
	: view(new InBattleView()), game(game)
{

}

InBattle::~InBattle()
{
	delete view;
}

void InBattle::engageInBattle() const
{
}
