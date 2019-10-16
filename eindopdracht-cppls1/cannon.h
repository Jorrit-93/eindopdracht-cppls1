#pragma once
#include "cannon_type.h"

class Cannon
{
private:
	CannonType type;
	int price = 0;
	int max_damage = 0;

public:
	Cannon(CannonType type, int price, int max_damage);

	int getPrice() const;
	int getDamage() const;
};
