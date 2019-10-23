#pragma once
#include "harbor_view.h"
#include "game.h"
#include "harbor.h"
#include "harbor_distance_struct.h"
#include "stock_amount_struct.h"
#include "stock_price_struct.h"
#include "harbor_builder.h"

class Game;

class HarborController
{
private:
	HarborView* view;
	Game& game;

	HarborBuilder* harbor_builder;
	
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
