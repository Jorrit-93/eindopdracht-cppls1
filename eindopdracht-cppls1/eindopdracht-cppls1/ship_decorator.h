#pragma once
#include "ship.h"

class ShipDecorator : public IShip
{
protected:
	IShip* ship;
	
public:
	ShipDecorator(IShip* ship);

	bool hasFled() override;
};
