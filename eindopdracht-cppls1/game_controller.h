#pragma once
#include "game_view.h"
#include "harbor_controller.h"
#include "sea_controller.h"
#include "battle_controller.h"
#include "i_ship.h"
#include "stock.h"
#include "ship_builder.h"

class HarborController;
class SeaController;
class BattleController;

class GameController
{
private:
	bool is_playing = true;
	
	GameView* view;
	HarborController* harbor_c;
	SeaController* sea_c;
	BattleController* battle_c;
	IController* current_c = nullptr;

	ShipBuilder* ship_builder;
	
	IShip* ship = nullptr;
	Dictionary<Stock, int>* stocks = new Dictionary<Stock, int>();
	int gold = 0;

public:
	GameController();
	~GameController();
	
	void initialize();
	void start();
	void win();
	void gameOver();
	void redo();
	void quit();
	void generalInfo() const;

	void moveToHarbor(HarborName name);
	void moveToSea();
	void engageInBattle();

	IShip& getShip() const;
	void setShip(ShipType type);
	void addGold(int value);
	void addStock(Stock* stock, int amount) const;
	int getGold() const;
	Dictionary<Stock, int>* getStocks() const;
	void setStocks(Dictionary<Stock, int>* stocks);
};
