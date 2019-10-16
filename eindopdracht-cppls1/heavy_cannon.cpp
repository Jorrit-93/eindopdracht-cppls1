#include "heavy_cannon.h"

HeavyCannon::HeavyCannon()
{
	max_damage = 6;
}

int HeavyCannon::getDamage()
{
	return Cannon::getDamage();
}
