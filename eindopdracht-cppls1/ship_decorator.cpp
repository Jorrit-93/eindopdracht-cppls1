#include "ship_decorator.h"

ShipDecorator::ShipDecorator(IShip* ship) : ship(ship)
{
	
}

ShipDecorator::~ShipDecorator()
{
	delete ship;
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
	ship->shoot(at);
}

int ShipDecorator::sail(WindType type, int destination)
{
	return ship->sail(type, destination);
}

ShipType ShipDecorator::getType()
{
	return ship->getType();
}

int ShipDecorator::getPrice()
{
	return ship->getPrice();
}

int ShipDecorator::getCargoSpace()
{
	return ship->getCargoSpace();
}

Array<Cannon*>* ShipDecorator::getCannons()
{
	return ship->getCannons();
}
int ShipDecorator::getHP()
{
	return ship->getHP();
}
Array<ShipTrait>* ShipDecorator::getTraits()
{
	return ship->getTraits();
}
