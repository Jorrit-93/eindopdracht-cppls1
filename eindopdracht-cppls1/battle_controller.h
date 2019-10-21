#pragma once
#include "battle_view.h"
#include "game.h"
#include "battle.h"

class Game;

class BattleController
{
private:
	BattleView* view;
	Game& game;

	Battle* battle = nullptr;
	
public:
	BattleController(Game& game);
	~BattleController();

	void instantiateBattle(HarborName destination, int distance);
	void enterBattle() const;
	void exitBattle() const;
};
