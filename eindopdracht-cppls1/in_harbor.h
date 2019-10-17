#pragma once
#include "in_harbor_view.h"
#include "game.h"

class Game;

class InHarbor
{
private:
	InHarborView* view;
	Game& game;
	
public:
	InHarbor(Game& game);
	~InHarbor();

	void moveToHarbor(HarborName name) const;
	void options() const;
};
