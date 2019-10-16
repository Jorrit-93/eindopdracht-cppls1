#include "ship_builder.h"
#include "ship.h"
#include "light_ship.h"
#include "small_ship.h"
#include "heavy_ship.h"

ShipBuilder::~ShipBuilder()
{
	delete attributes_def;
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

ShipBuilder& ShipBuilder::setAttributes(Array<ShipAttribute>* attributes)
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
		case ShipAttribute::Small:
			ship = new SmallShip(ship);
			break;
		case ShipAttribute::Light:
			ship = new LightShip(ship);
			break;
		case ShipAttribute::Heavy:
			ship = new HeavyShip(ship);
			break;
		}
	}
	return ship;
}
