#pragma once

class IShip
{
public:
	virtual ~IShip() {}

	virtual bool hasFled() = 0;
};