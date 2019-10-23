#pragma once
#include "harbor_view.h"
#include "game_controller.h"
#include "harbor.h"

class GameController;

class HarborController
{
private:
	HarborView* view;
	GameController& game;

	Harbor* harbor = nullptr;
	
public:
	HarborController(GameController& game);
	~HarborController();

	void moveToHarbor(HarborName name);
	void enterHarbor() const;
	void exitHarbor(HarborName name, int distance) const;
};
