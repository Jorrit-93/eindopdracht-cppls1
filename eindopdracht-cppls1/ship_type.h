#pragma once
#include <ostream>
#include "string.h"

enum class ShipType
{
	Pinnace,
	Sloep,
	Brigg,
	Barque,
	Korvet,
	Fluyt,
	Fregat,
	Galjoen,
	Handelsfluyt,
	Caravel,
	Carrack,
	Oorlogsgaljoen,
	Ship_of_the_Line,
};

std::ostream& operator<<(std::ostream& os, ShipType ship_type);

ShipType getShipType(String* s);



