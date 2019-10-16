#pragma once
#include "i_ship.h"
#include "ship_type.h"
#include "array.h"
#include "cannon.h"

class Ship : public IShip
{
protected:
	ShipType type;
	int price;
	int cargo_space;
	Array<Cannon*>* cannons;
	int hp;
	
public:
	Ship(ShipType type, int price, int cargo_space, int cannon_amount, int hp);
	~Ship();
	
	bool hasFled() override;
};