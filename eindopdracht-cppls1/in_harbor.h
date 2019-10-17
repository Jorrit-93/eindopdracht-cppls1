#pragma once
#include "in_harbor_view.h"

class Game;

class InHarbor
{
private:
	InHarborView* view;
	Game* game;
	
public:
	InHarbor(Game* game);
	~InHarbor();

	void moveToHarbor(HarborName name) const;
};
