#pragma once
#include "i_ship.h"
#include "ship_type.h"
#include "array.h"
#include "cannon.h"

class Ship : public IShip
{
protected:
	ShipType type;
	int price;
	int cargo_space;
	Array<Cannon*>* cannons = nullptr;
	List<ShipTrait>* traits = nullptr;
	int hp;
	
public:
	Ship(ShipType type, int price, int cargo_space, int cannon_amount, int hp);
	~Ship();
	Ship(const Ship& other);
	Ship& operator=(const Ship& other);
	Ship(Ship&& other) noexcept;
	Ship& operator=(Ship&& other) noexcept;
	
	bool hasSunk() override;
	bool hasFled(IShip& from) override;
	void shoot(IShip& at) override;
	int sail(WindType type, int distance) override;

	ShipType getType() override;
	int getPrice() override;
	int getCargoSpace() override;
	Array<Cannon*>* getCannons() override;
	int getHP() override;
	void setHP(const int& hp) override;
	List<ShipTrait>* getTraits() override;
};