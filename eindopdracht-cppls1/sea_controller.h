#pragma once
#include "sea_view.h"
#include "game.h"
#include "sea.h"

class Game;

class SeaController
{
private:
	SeaView* view;
	Game& game;
	
	Sea* sea = nullptr;
	
public:
	SeaController(Game& game);
	~SeaController();

	void moveToSea(HarborName destination, int distance);
	void enterSea() const;
	void exitSea() const;
};
