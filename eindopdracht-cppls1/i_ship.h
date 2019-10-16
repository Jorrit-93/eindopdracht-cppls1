#pragma once

class IShip
{
public:
	virtual ~IShip() = default;
	
protected:
	virtual bool hasFled() = 0;
};