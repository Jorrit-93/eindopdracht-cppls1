#pragma once
#include "wind_type.h"
#include "ship_trait.h"
#include "array.h"

class IShip
{
public:
	virtual ~IShip() = default;

	virtual bool hasSunk() = 0;
	virtual bool hasFled(IShip& from) = 0;
	virtual void shoot(IShip& at) = 0;
	virtual int sail(WindType type, int distance) = 0;
	virtual Array<ShipTrait>* getTraits() = 0;
};
