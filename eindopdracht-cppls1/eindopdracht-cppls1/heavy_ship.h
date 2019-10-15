#pragma once
#include "ship_decorator.h"

class HeavyShip : public ShipDecorator
{
public:
	HeavyShip(IShip* ship);
};
