#include "pirate_ship.h"
#include "random.h"
#include <iostream>

PirateShip::PirateShip() : Ship(ShipType::Pinnace, 0, 0, Random::global()->randomInt(8, 50), Random::global()->randomInt(100, 300))
{
	// Initialize type & hp
	type = static_cast<ShipType>(Random::global()->randomInt(0, 11));
	hp = Random::global()->randomInt(100, 340);

	// Initialize cannons
	for(auto i = 0; i < cannons->size(); i ++)
	{
		auto max_damage = 0;
		const auto type = static_cast<CannonType>(Random::global()->randomInt(0, 2));

		switch(type)
		{
		case CannonType::licht :
			max_damage = 2;
			break;
		case CannonType::medium:
			max_damage = 4;
			break;
		case CannonType::zwaar:
			max_damage = 6;
			break;
		}
		
		auto* cannon = new Cannon(type, 0, max_damage);
		cannons->add(cannon);
	}
}

PirateShip::~PirateShip()
{
	
}
