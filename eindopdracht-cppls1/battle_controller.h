#pragma once
#include "battle_view.h"
#include "game_controller.h"
#include "battle.h"
#include "pirate_ship.h"

class GameController;

class BattleController
{
private:
	BattleView* view;
	GameController& game;

	bool is_over = false;
	IShip* pirate_ship;
	
public:
	BattleController(GameController& game);
	~BattleController();

	void initialize();
	void enterBattle();
	void exitBattle();
};
