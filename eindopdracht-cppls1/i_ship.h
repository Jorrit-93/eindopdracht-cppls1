#pragma once
#include "wind_type.h"
#include "ship_trait.h"
#include "ship_type.h"
#include "cannon.h"
#include "array.h"

class IShip
{	
public:
	virtual ~IShip() = default;

	virtual bool hasSunk() = 0;
	virtual bool hasFled(IShip& from) = 0;
	virtual void shoot(IShip& at) = 0;
	virtual int sail(WindType type, int distance) = 0;

	virtual ShipType getType() = 0;
	virtual int getPrice() = 0;
	virtual int getCargoSpace() = 0;
	virtual Array<Cannon*>* getCannons() = 0;
	virtual int getHP() = 0;
	virtual List<ShipTrait>* getTraits() = 0;
};
