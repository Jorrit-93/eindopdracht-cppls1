#include "cannon.h"

Cannon::Cannon(const CannonType type, const int price, const int max_damage)
	: type(type), price(price), damage(new RandomValue(0, max_damage))
{
	damage->setRandomValue();
}
Cannon::~Cannon()
{
	delete damage;
}

//copy
Cannon::Cannon(const Cannon& other)
{
	*this = other;
}
Cannon& Cannon::operator=(const Cannon& other)
{
	delete damage;
	damage = new RandomValue(*other.damage);
	type = other.type;
	price = other.price;
	return *this;
}

//move
Cannon::Cannon(Cannon&& other) noexcept
{
	*this = other;
}
Cannon& Cannon::operator=(Cannon&& other) noexcept
{
	delete damage;
	damage = other.damage;
	other.damage = nullptr;
	type = other.type;
	price = other.price;
	return *this;
}

CannonType Cannon::getType() const
{
	return type;
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
