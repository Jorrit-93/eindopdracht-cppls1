#pragma once
#include "harbor_view.h"
#include "game_controller.h"
#include "harbor.h"
#include "harbor_distance_struct.h"
#include "stock_amount_struct.h"
#include "stock_price_struct.h"
#include "harbor_builder.h"

class GameController;

class HarborController
{
private:
	HarborView* view;
	GameController& game;

	HarborBuilder* harbor_builder;
	
	Harbor* harbor = nullptr;
	
public:
	HarborController(GameController& game);
	~HarborController();

	void instantiateHarbor(HarborName name);
	void enterHarbor();
	void exitHarbor(HarborName name, int distance) const;

	void buyStock();
	void buyCannon();
	void buyShip();
	void repairShip();
	void bonVoyage();
};
