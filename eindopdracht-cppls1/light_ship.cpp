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
