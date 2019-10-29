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
	
	GameView* view = nullptr;
	HarborController* harbor_c = nullptr;
	SeaController* sea_c = nullptr;
	BattleController* battle_c = nullptr;
	IController* current_c = nullptr;

	ShipBuilder* ship_builder = nullptr;
	
	IShip* ship = nullptr;
	Dictionary<StockType, int>* cargo = new Dictionary<StockType, int>();
	int hp = 0;
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
	void moveToSea(HarborName destination, int distance);
	void moveToSea();
	void engageInBattle();

	IShip& getShip() const;
	void setShip(ShipType type);

	Dictionary<StockType, int>* getCargo() const;
	int getCargoSize() const;
	void addCargo(StockType cargo, int amount) const;
	void removeCargo(StockType stock, int amount) const;

	int getHP() const;
	void addHP(int value);

	int getGold() const;
	void addGold(int value);
};
