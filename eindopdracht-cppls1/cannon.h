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
	Cannon() = default;
	Cannon(CannonType type, int price, int max_damage);
	~Cannon();

	CannonType getType() const;
	int getPrice() const;
	int getDamage() const;
};
