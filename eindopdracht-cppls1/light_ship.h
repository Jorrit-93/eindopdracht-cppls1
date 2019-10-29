#pragma once
#include "ship_decorator.h"

class LightShip : public ShipDecorator
{
public:
	LightShip(IShip* ship);

	int sail(WindType type, int distance) override;
	bool hasFled(IShip& from) override;
	List<ShipTrait>* getTraits() override;
};
