#include "light_cannon.h"

LightCannon::LightCannon()
{
	max_damage = 2;
}

int LightCannon::getDamage()
{
	return Cannon::getDamage();
}
