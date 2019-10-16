#include "cannon.h"
#include "random.h"

Cannon::Cannon(const CannonType type, const int price, const int max_damage)
	: type(type), price(price), max_damage(max_damage)
{
	
}

int Cannon::getPrice() const
{
	return price;
}

int Cannon::getDamage() const
{
	return Random::global()->randomInt(0, max_damage);
}
