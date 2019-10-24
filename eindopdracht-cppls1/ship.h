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
	Array<Cannon>* cannons;
	int hp;
	
public:
	Ship(ShipType type, int price, int cargo_space, int cannon_amount, int hp);
	~Ship();
	
	bool hasSunk() override;
	bool hasFled(IShip& from) override;
	void shoot(IShip& at) override;
	int sail(WindType type, int distance) override;

	ShipType getType() override;
	int getPrice() override;
	int getCargoSpace() override;
	Array<Cannon>* getCannons() override;
	int getHP() override;
	Array<ShipTrait>* getTraits() override;
};