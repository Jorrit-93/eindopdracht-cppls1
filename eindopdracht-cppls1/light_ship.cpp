#include "light_ship.h"

LightShip::LightShip(IShip* ship) : ShipDecorator(ship)
{
	
}

int LightShip::sail(WindType type, int distance)
{
	if(type == WindType::briesje)
	{
		distance--;
	}
	return ship->sail(type, distance);
}

bool LightShip::hasFled(IShip& from)
{
	auto* traits = from.getTraits();
	
	return true;
}

List<ShipTrait>* LightShip::getTraits()
{
	auto traits = ship->getTraits();

	traits->add(ShipTrait::licht);

	return traits;
}


