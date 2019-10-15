#include "ship.h"

Ship::Ship(const int cannon_amount) : cannons(new Array<Cannon*>(cannon_amount))
{
	
}

bool Ship::hasFled()
{
	return false;
}
