#pragma once
#include "i_controller.h"
#include "sea_view.h"
#include "game_controller.h"
#include "sea.h"

class GameController;

class SeaController : public IController
{
private:
	SeaView* view;
	GameController& game;
	
	Sea* sea = nullptr;
	
public:
	SeaController(GameController& game);
	~SeaController();

	void instantiate(HarborName destination, int distance);
	void enter() override;
	void exit() override;
};
