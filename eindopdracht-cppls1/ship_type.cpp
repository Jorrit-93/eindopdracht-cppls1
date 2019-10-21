#include "ship_type.h"
#include "string.h"

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


ShipType GetShipType(const String& s)
{
	Dictionary<const char*, ShipType> types = Dictionary<const char*, ShipType>();

	types.add("Pinnance", ShipType::Pinnance);
	types.add("Sloep", ShipType::Sloep);
	types.add("Brigg", ShipType::Brigg);
	types.add("Barque", ShipType::Barque);
	types.add("Korvet", ShipType::Korvet);
	types.add("Fluyt", ShipType::Fluyt);
	types.add("Fregat", ShipType::Fregat);
	types.add("Galjoen", ShipType::Galjoen);
	types.add("Handelsfluyt", ShipType::Handelsfluyt);
	types.add("Caravel", ShipType::Caravel);
	types.add("Oorlogsgaljoen", ShipType::Oorlogsgaljoen);
	types.add("Ship of the line", ShipType::Ship_of_the_line);

	auto test = types.get(s.toCharArray());
	return test;
}
