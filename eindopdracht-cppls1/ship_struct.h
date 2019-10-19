#pragma once
#include "result_struct.h"
#include "ship_type.h"
#include "ship_traits.h"

struct ShipStruct : ResultStruct
{
	ShipType type;
	int price;
	int storage_capacity;
	int cannons;
	int health;
	List<ShipTrait>* traits;
};
