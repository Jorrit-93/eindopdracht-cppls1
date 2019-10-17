#pragma once
#include "on_sea_view.h"
#include "game.h"

class Game;

class OnSea
{
private:
	OnSeaView* view;
	Game& game;
	
public:
	OnSea(Game& game);
	~OnSea();

	void moveToSea() const;
};
