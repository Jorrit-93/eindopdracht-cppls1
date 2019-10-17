# include "in_harbor.h"

InHarbor::InHarbor(Game* game)
	: game(game)
{
	
}

InHarbor::~InHarbor()
{
	delete view;
}
