#include "ship_decorator.h"

ShipDecorator::ShipDecorator(IShip* ship) : ship(ship)
{
	
}

bool ShipDecorator::hasFled()
{
	return ship->hasFled();
}
