#include "small_ship.h"
#include "random.h"

SmallShip::SmallShip(IShip* ship) : ShipDecorator(ship)
{
	
}

bool SmallShip::hasFled(IShip& from)
{
	auto* traits = getTraits();
	
	return true;
}

List<ShipTrait>* SmallShip::getTraits()
{
	auto traits = ship->getTraits();

	traits->add(ShipTrait::klein);

	return traits;
}
