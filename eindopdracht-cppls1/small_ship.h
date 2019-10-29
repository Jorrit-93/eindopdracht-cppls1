#pragma once
#include "ship_decorator.h"

class SmallShip : public ShipDecorator
{
public:
	SmallShip(IShip* ship);
	bool hasFled(IShip& from) override;
	List<ShipTrait>* getTraits() override;
};
