#include "small_ship.h"
#include "random.h"

SmallShip::SmallShip(IShip* ship) : ShipDecorator(ship)
{
	
}

bool SmallShip::hasFled(const IShip& from)
{
	
	return true;
}
