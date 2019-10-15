#pragma once
#include "ship_decorator.h"

class LightShip : public ShipDecorator
{
public:
	LightShip(IShip* ship);
};
