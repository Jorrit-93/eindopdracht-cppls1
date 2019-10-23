#pragma once
#include "game_view.h"
#include "harbor_controller.h"
#include "sea_controller.h"
#include "battle_controller.h"
#include "i_ship.h"
#include "stock.h"
#include "ship_struct.h"
#include "ship_builder.h"

class HarborController;
class SeaController;
class BattleController;

class Game
{
private:
	GameView* view;
	HarborController* in_harbor;
	SeaController* on_sea;
	BattleController* in_battle;

	ShipBuilder* ship_builder;
	
	IShip* ship = nullptr;
	Dictionary<Stock*, int>* stocks;
	int gold = 0;

public:
	Game();
	~Game();
	
	void start();
	void win();
	void gameOver();
	void redo();
	void quit() const;
	void generalInfo() const;

	void moveToHarbor(HarborName name) const;
	void moveToSea(HarborName name, int distance) const;
	void engageInBattle( HarborName name, int distance) const;

	IShip& getShip() const;
	void setShip(ShipType type);
	void addGold(int value);
};
