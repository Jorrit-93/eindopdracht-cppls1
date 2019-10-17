# include "on_sea.h"

OnSea::OnSea(Game* game)
	: game(game)
{
	
}

OnSea::~OnSea()
{
	delete view;
}
