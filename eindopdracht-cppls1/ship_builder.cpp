#include "ship_builder.h"
#include "parser_controller.h"
#include "ship.h"
#include "light_ship.h"
#include "small_ship.h"
#include "heavy_ship.h"

ShipBuilder::ShipBuilder()
{
	const auto parserController = ParserController();
	ship_structs = parserController.parseShips();
}

ShipBuilder::~ShipBuilder()
{
	delete attributes_def;
	delete ship_structs;
}

IShip* ShipBuilder::createShip(ShipType type)
{
	int i = 0;
	auto ship = ship_structs->getAt(i);
	while (ship->type != type)
	{
		ship = ship_structs->getAt(i);
		i++;
	}
	return setType(ship->type)
		.setPrice(ship->price)
		.setCargoSpace(ship->storage_capacity)
		.setCannonAmount(ship->cannons)
		.setHP(ship->health)
		.setAttributes(ship->traits)
		.build();
}

ShipBuilder& ShipBuilder::setType(const ShipType type)
{
	type_def = type;
	return *this;
}

ShipBuilder& ShipBuilder::setPrice(const int price)
{
	price_def = price;
	return *this;
}

ShipBuilder& ShipBuilder::setCargoSpace(const int cargo_space)
{
	cargo_space_def = cargo_space;
	return *this;
}

ShipBuilder& ShipBuilder::setCannonAmount(const int cannon_amount)
{
	cannon_amount_def = cannon_amount;
	return *this;
}
ShipBuilder& ShipBuilder::setHP(const int hp)
{
	hp_def = hp;
	return *this;
}

ShipBuilder& ShipBuilder::setAttributes(Array<ShipTrait>* attributes)
{
	delete attributes_def;
	attributes_def = attributes;
	return *this;
}

IShip* ShipBuilder::build() const
{
	IShip* ship = new Ship(type_def, price_def, cargo_space_def, cannon_amount_def, hp_def);

	for(int i = 0; i < attributes_def->count(); i++)
	{
		switch (attributes_def->getAt(i))
		{
		case ShipTrait::klein:
			ship = new SmallShip(ship);
			break;
		case ShipTrait::licht:
			ship = new LightShip(ship);
			break;
		case ShipTrait::log:
			ship = new HeavyShip(ship);
			break;
		}
	}
	return ship;
}
