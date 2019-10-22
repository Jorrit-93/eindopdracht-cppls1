#include "cannon.h"

Cannon::Cannon(const CannonType type, const int price, const int max_damage)
	: type(type), price(price), damage(new RandomValue(0, max_damage))
{
	damage->setRandomValue();
}

int Cannon::getPrice() const
{
	return price;
}

int Cannon::getDamage() const
{
	damage->setRandomValue();
	return damage->getValue();
}
