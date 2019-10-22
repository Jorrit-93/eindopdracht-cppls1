#pragma once
#include "ship.h"

class ShipDecorator : public IShip
{
protected:
	IShip* ship;
	
public:
	ShipDecorator(IShip* ship);

	bool hasSunk() override;
	bool hasFled() override;
	int sail(WindType type, int destination) override;
};
