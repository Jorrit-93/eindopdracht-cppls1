#pragma once
#include "i_controller.h"
#include "battle_view.h"
#include "game_controller.h"
#include "battle.h"
#include "pirate_ship.h"

class GameController;

class BattleController : public IController
{
private:
	BattleView* view;
	GameController& game;

	bool is_over = false;
	IShip* pirate_ship;
	
public:
	BattleController(GameController& game);
	~BattleController();

	void instantiate();
	void enter() override;
	void exit() override;
};
