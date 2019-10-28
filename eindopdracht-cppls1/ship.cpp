#include "ship.h"
#include "random.h"

Ship::Ship(ShipType type, int price, int cargo_space, int cannon_amount, int hp)
	: type(type), price(price), cargo_space(cargo_space), cannons(new Array<Cannon*>(cannon_amount)), hp(hp)
{
}

Ship::~Ship()
{
	delete cannons;
}

//copy
Ship::Ship(const Ship& other)
{
	*this = other;
}

Ship& Ship::operator=(const Ship& other)
{
	type = other.type;
	price = other.price;
	cargo_space = other.cargo_space;
	hp = other.hp;
	
	delete cannons;
	if (other.cannons)
	{
		cannons = new Array<Cannon*>(*other.cannons);
	}
	
	return *this;
}

//move
Ship::Ship(Ship&& other) noexcept
{
	*this = std::move(other);
}

Ship& Ship::operator=(Ship&& other) noexcept
{
	type = other.type;
	price = other.price;
	cargo_space = other.cargo_space;
	hp = other.hp;

	delete cannons;
	cannons = other.cannons;
	other.cannons = nullptr;
	
	return *this;
}

bool Ship::hasSunk()
{
	return hp <= 0;
}

bool Ship::hasFled(IShip& from)
{
	Array<ShipTrait>* traits = from.getTraits();

	if (traits->contains(ShipTrait::licht)) 
		return Random::global()->chance(50);

	if (traits->contains(ShipTrait::log))
		return Random::global()->chance(75);

	if(traits->count() == 0)
		Random::global()->chance(60);
	
	throw;
}

void Ship::shoot(IShip& at)
{
	
}

int Ship::sail(WindType type, int distance)
{
	switch (type)
	{
	case WindType::geen:
	case WindType::briesje:
		return distance;
	case WindType::zwak:
	case WindType::normaal:
		return distance - 1;
	case WindType::sterk:
		return distance - 2;
	case WindType::storm:
		hp -= hp / 100;
		switch(Random::global()->randomInt(1, 5))
		{
		case 1:
		case 2:
			return distance + 1;
		case 3:
		case 4:
			return distance - 1;
		case 5:
			return distance - 2;
		}
	}
	throw; //wind_type not valid
}

ShipType Ship::getType()
{
	return type;
}

int Ship::getPrice()
{
	return price;
}

int Ship::getCargoSpace()
{
	return cargo_space;
}

Array<Cannon*>* Ship::getCannons()
{
	return cannons;
}

int Ship::getHP()
{
	return hp;
}

Array<ShipTrait>* Ship::getTraits()
{
	Array<ShipTrait>* traits = new Array<ShipTrait>(5);

	return traits;
}
