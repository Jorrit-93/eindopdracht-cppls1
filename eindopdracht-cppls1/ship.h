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
	Ship(int cannon_amount);

	bool hasSunk() override;
	bool hasFled(const IShip& from) override;
	void shoot(IShip& at) override;
	int sail(WindType type, int distance) override;
};
