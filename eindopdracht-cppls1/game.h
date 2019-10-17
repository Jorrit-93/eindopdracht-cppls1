#pragma once
#include "game_view.h"
#include "in_harbor.h"
#include "on_sea.h"
#include "in_battle.h"
#include "i_ship.h"

class InHarbor;
class OnSea;
class InBattle;

class Game
{
private:
	GameView* view;
	InHarbor* in_harbor;
	OnSea* on_sea;
	InBattle* in_battle;

	IShip* ship = nullptr;
	int gold = 0;

public:
	Game();
	~Game();

	void initiate();
	
	void start();
	void win();
	void gameOver();
	void redo();
	void quit() const;
	void generalInfo() const;

	void moveToHarbor(HarborName name) const;
	void moveToSea() const;
	void engageInBattle() const;

	void setShip(ShipType type);
	void addGold(int value);
};
