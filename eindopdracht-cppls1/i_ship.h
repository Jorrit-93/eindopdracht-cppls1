#pragma once

class IShip
{	
public:
	virtual ~IShip() = default;
	
	virtual bool hasFled() = 0;
};