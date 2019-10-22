#pragma once
#include "harbor_view.h"
#include "game.h"
#include "harbor.h"

class Game;

class HarborController
{
private:
	HarborView* view;
	Game& game;

	Harbor* harbor = nullptr;
	
public:
	HarborController(Game& game);
	~HarborController();

	void instantiateHarbor(HarborName name);
	void enterHarbor() const;
	void exitHarbor(HarborName name, int distance) const;

	void buyStock();
	void buyCannon();
	void buyShip();
	void repairShip();
	void bonVoyage();
};
