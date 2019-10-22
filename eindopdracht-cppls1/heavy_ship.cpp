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
