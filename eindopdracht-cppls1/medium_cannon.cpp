#include "medium_cannon.h"

MediumCannon::MediumCannon()
{
	max_damage = 4;
}

int MediumCannon::getDamage()
{
	return Cannon::getDamage();
}
