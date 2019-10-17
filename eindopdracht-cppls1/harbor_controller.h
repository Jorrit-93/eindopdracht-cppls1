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

	void moveToHarbor(HarborName name);
	void enterHarbor() const;
	void exitHarbor(HarborName name, int distance) const;
};
