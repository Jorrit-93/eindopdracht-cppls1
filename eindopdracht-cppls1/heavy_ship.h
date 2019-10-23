#pragma once
#include "ship_decorator.h"

class HeavyShip : public ShipDecorator
{
public:
	HeavyShip(IShip* ship);
	
	int sail(WindType type, int distance) override;
	bool hasFled(const IShip& from) override;
};
