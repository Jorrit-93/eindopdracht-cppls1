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
	Array<ShipTrait>* traits = nullptr;

	ShipStruct() = default;
	~ShipStruct()
	{
		delete traits;
	}

	//copy
	ShipStruct(const ShipStruct& other)
	{
		*this = other;
	}
	ShipStruct& operator=(const ShipStruct& other)
	{
		delete traits;
		traits = new Array<ShipTrait>(*other.traits);
		type = other.type;
		price = other.price;
		storage_capacity = other.storage_capacity;
		cannons = other.cannons;
		health = other.health;
		return *this;
	}

	//move
	ShipStruct(ShipStruct&& other) noexcept
	{
		*this = other;
	}
	ShipStruct& operator=(ShipStruct&& other) noexcept
	{
		delete traits;
		traits = other.traits;
		other.traits = nullptr;
		type = other.type;
		price = other.price;
		storage_capacity = other.storage_capacity;
		cannons = other.cannons;
		health = other.health;
		return *this;
	}
};
