#pragma once
#include "wind_type.h"

class IShip
{
public:
	virtual ~IShip() = default;

	virtual bool hasSunk() = 0;
	virtual bool hasFled() = 0;
	virtual int sail(WindType type, int distance) = 0;
};
