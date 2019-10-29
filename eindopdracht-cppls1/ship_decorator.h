#pragma once
#include "ship.h"

class ShipDecorator : public IShip
{
protected:
	IShip* ship = nullptr;
	
public:
	ShipDecorator(IShip* ship);
	~ShipDecorator();
	
	bool hasSunk() override;
	bool hasFled(IShip& from) override;
	void shoot(IShip& at) override;
	int sail(WindType type, int destination) override;

	ShipType getType() override;
	int getPrice() override;
	int getCargoSpace() override;
	Array<Cannon*>* getCannons() override;
	int getHP() override;
	List<ShipTrait>* getTraits() override;
};
