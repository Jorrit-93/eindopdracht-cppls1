#pragma once
#include <ostream>

enum class ShipType
{
	Pinnance,
	Sloep,
	Brigg,
	Barque,
	Korvet,
	Fluyt,
	Fregat,
	Galjoen,
	Handelsfluyt,
	Caravel,
	Oorlogsgaljoen,
	Ship_of_the_line,
};

std::ostream& operator<<(std::ostream& os, ShipType& ship_type);