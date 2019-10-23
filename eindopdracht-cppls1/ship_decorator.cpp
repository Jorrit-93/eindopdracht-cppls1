#include "ship_decorator.h"

ShipDecorator::ShipDecorator(IShip* ship) : ship(ship)
{
	
}

bool ShipDecorator::hasSunk()
{
	return ship->hasSunk();
}

bool ShipDecorator::hasFled(IShip& from)
{
	return ship->hasFled(from);
}

void ShipDecorator::shoot(IShip& at)
{
	
}

int ShipDecorator::sail(WindType type, int destination)
{
	return ship->sail(type, destination);
}

Array<ShipTrait>* ShipDecorator::getTraits()
{
	return ship->getTraits();
}
