#pragma once
#include "ship_decorator.h"

class SmallShip : public ShipDecorator
{
public:
	SmallShip(IShip* ship);
};
