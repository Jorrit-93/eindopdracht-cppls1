#pragma once
#include "wind_type.h"

class IShip
{
public:
	virtual ~IShip() = default;

	virtual bool hasSunk() = 0;
	virtual bool hasFled(const IShip& from) = 0;
	virtual void shoot(IShip& at) = 0;
	virtual int sail(WindType type, int distance) = 0;
};
