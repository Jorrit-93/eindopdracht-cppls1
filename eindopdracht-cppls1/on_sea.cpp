# include "on_sea.h"
#include "game.h"

OnSea::OnSea(Game& game)
	: view(new OnSeaView()), game(game)
{

}

OnSea::~OnSea()
{
	delete view;
}

void OnSea::moveToSea() const
{
}
