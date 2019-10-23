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

bool Ship::hasSunk()
{
	return hp <= 0;
}

bool Ship::hasFled()
{
	return false;
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
