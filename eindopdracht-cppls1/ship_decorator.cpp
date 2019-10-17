#include "ship_decorator.h"

ShipDecorator::ShipDecorator(IShip* ship) : ship(ship)
{
	
}

bool ShipDecorator::hasSunk()
{
	return ship->hasSunk();
}

bool ShipDecorator::hasFled()
{
	return ship->hasFled();
}

int ShipDecorator::sail(WindType type, int destination)
{
	return ship->sail(type, destination);
}
