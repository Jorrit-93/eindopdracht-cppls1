#pragma once
#include "in_harbor.h"
#include "on_sea.h"
#include "in_battle.h"
#include "game_view.h"

class Game
{
private:
	GameView* view;
	InHarbor* in_harbor;
	OnSea* on_sea;
	InBattle* in_battle;

public:
	Game();
	~Game();

	void start() const;
	void win() const;
	void gameOver() const;
	void quit() const;

	void moveToHarbor(HarborName name) const;
	void moveToSea() const;
	void engageInBattle() const;
};
