#pragma once
#include "cannon_type.h"
#include "random_value.h"

class Cannon
{
private:
	CannonType type;
	int price = 0;
	RandomValue* damage = nullptr;

public:
	Cannon() = default;
	Cannon(CannonType type, int price, int max_damage);
	~Cannon();
	Cannon(const Cannon& other);
	Cannon& operator=(const Cannon& other);
	Cannon(Cannon&& other) noexcept;
	Cannon& operator=(Cannon&& other) noexcept;
	

	CannonType getType() const;
	int getPrice() const;
	int getDamage() const;
};
