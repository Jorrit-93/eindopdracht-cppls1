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

	bool isOver = false;
	IShip* pirate_ship;
	
public:
	BattleController(GameController& game);
	~BattleController();

	void initialize();
	void enterBattle() const;
	void exitBattle() const;
};
