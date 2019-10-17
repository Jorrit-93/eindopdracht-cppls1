#pragma once
#include "in_battle_view.h"
#include "game.h"

class Game;

class InBattle
{
private:
	InBattleView* view;
	Game& game;
	
public:
	InBattle(Game& game);
	~InBattle();

	void engageInBattle() const;
};
