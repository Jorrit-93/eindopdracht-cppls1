#pragma once
#include "battle_view.h"
#include "game_controller.h"
#include "battle.h"

class GameController;

class BattleController
{
private:
	BattleView* view;
	GameController& game;

	Battle* battle = nullptr;
	
public:
	BattleController(GameController& game);
	~BattleController();

	void engageInBattle(HarborName destination, int distance);
	void enterBattle() const;
	void exitBattle() const;
};
