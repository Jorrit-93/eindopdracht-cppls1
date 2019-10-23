#include "heavy_ship.h"

HeavyShip::HeavyShip(IShip* ship) : ShipDecorator(ship)
{
	
}

int HeavyShip::sail(WindType type, int distance)
{
	if (type == WindType::zwak)
	{
		distance++;
	}
	return ship->sail(type, distance);
}

bool HeavyShip::hasFled(IShip& from)
{
	auto* traits = getTraits();
	
	return true;
}

Array<ShipTrait>* HeavyShip::getTraits()
{
	auto* traits = ship->getTraits();

	traits->add(ShipTrait::log);

	return traits;
}
