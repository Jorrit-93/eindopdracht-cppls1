#pragma once
#include "i_controller.h"
#include "harbor_view.h"
#include "game_controller.h"
#include "harbor_builder.h"
#include "harbor.h"

class GameController;

class HarborController : public IController
{
private:
	HarborView* view;
	GameController& game;
	HarborBuilder* harbor_builder;
	
	Harbor* harbor = nullptr;
	
public:
	HarborController(GameController& game);
	~HarborController();

	void instantiate(HarborName name);
	void enter() override;
	void exit() override;

	void buyStock();
	void buyCannon();
	void buyShip();
	void repairShip();
	void bonVoyage();
};
