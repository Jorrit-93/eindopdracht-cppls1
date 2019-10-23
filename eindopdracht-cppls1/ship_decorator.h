#pragma once
#include "ship.h"

class ShipDecorator : public IShip
{
protected:
	IShip* ship;
	
public:
	ShipDecorator(IShip* ship);

	bool hasSunk() override;
	bool hasFled(const IShip& from) override;
	void shoot(IShip& at) override;
	int sail(WindType type, int destination) override;
};
