#pragma once
#include "ship_type.h"
#include "ship_trait.h"

struct ShipStruct
{
public:
	ShipType type;
	int price;
	int storage_capacity;
	int cannons;
	int health;
	Array<ShipTrait>* traits;

	~ShipStruct() { delete traits; }
};
