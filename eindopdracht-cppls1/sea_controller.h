#pragma once
#include "sea_view.h"
#include "game_controller.h"
#include "sea.h"

class GameController;

class SeaController
{
private:
	SeaView* view;
	GameController& game;
	
	Sea* sea = nullptr;
	
public:
	SeaController(GameController& game);
	~SeaController();

	void moveToSea(HarborName destination, int distance);
	void enterSea() const;
	void exitSea() const;
};
