#include "ship.h"

Ship::Ship(ShipType type, int price, int cargo_space, int cannon_amount, int hp)
	: type(type), price(price), cargo_space(cargo_space), cannons(new Array<Cannon*>(cannon_amount)), hp(hp)
{
}

Ship::~Ship()
{
	delete cannons;
}

bool Ship::hasFled()
{
	return false;
}
