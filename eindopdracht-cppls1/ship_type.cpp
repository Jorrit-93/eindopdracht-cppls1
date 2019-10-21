#include "ship_type.h"
#include "string.h"

// ShipType GetShipType(const String& s)
// {
// 	if (s == "Pinnance") return ShipType::Pinnance;
// 	if (s == "Sloep") return ShipType::Sloep;
// 	if (s == "Brigg") return ShipType::Brigg;
// 	if (s == "Barque") return ShipType::Barque;
// 	if (s == "Korvet") return ShipType::Korvet;
// 	if (s == "Fluyt") return ShipType::Fluyt;
// 	if (s == "Fregat") return ShipType::Fregat;
// 	if (s == "Galjoen") return ShipType::Galjoen;
// 	if (s == "Handelsfluyt") return ShipType::Handelsfluyt;
// 	if (s == "Caravel") return ShipType::Caravel;
// 	if (s == "Oorlogsgaljoen") return ShipType::Oorlogsgaljoen;
// 	if (s == "Ship of the Line") return ShipType::Ship_of_the_line;
// }

std::ostream& operator<<(std::ostream& os, ShipType& ship_type)
{
	{
		switch (ship_type) {
		case ShipType::Pinnance:
			os << "Pinnance";
			break;
		case ShipType::Sloep:
			os << "Sloep";
			break;
		case ShipType::Brigg:
			os << "Brigg";
			break;
		case ShipType::Barque:
			os << "Barque";
			break;
		case ShipType::Korvet:
			os << "Korvet";
			break;
		case ShipType::Fluyt:
			os << "Fluyt";
			break;
		case ShipType::Fregat:
			os << "Fregat";
			break;
		case ShipType::Galjoen:
			os << "Galjoen";
			break;
		case ShipType::Handelsfluyt:
			os << "Handelsfluyt";
			break;
		case ShipType::Caravel:
			os << "Caravel";
			break;
		case ShipType::Oorlogsgaljoen:
			os << "Oorlogsgaljoen";
			break;
		case ShipType::Ship_of_the_line:
			os << "Ship of the line";
			break;
		}

		return os;
	}
}