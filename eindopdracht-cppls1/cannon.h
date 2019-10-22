#pragma once
#include "cannon_type.h"
#include "random_value.h"

class Cannon
{
private:
	CannonType type;
	int price = 0;
	RandomValue* damage;

public:
	Cannon(CannonType type, int price, int max_damage);
	~Cannon();

	int getPrice() const;
	int getDamage() const;
};
