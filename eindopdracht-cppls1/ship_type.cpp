#include "ship_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const ShipType ship_type)
{
	const auto string = shipTypeToString(ship_type);
	os << string;
	return os;
}

String shipTypeToString(const ShipType ship_type)
{
	switch (ship_type)
	{
	case ShipType::Pinnace:
		return String("Pinnace");
	case ShipType::Sloep:
		return String("Sloep");
	case ShipType::Brigg:
		return String("Brigg");
	case ShipType::Barque:
		return String("Barque");
	case ShipType::Korvet:
		return String("Korvet");
	case ShipType::Fluyt:
		return String("Fluyt");
	case ShipType::Fregat:
		return String("Fregat");
	case ShipType::Galjoen:
		return String("Galjoen");
	case ShipType::Handelsfluyt:
		return String("Handelsfluyt");
	case ShipType::Caravel:
		return String("Caravel");
	case ShipType::Carrack:
		return String("Carrack");
	case ShipType::Oorlogsgaljoen:
		return String("Oorlogsgaljoen");
	case ShipType::Ship_of_the_Line:
		return String("Ship of the Line");
	}
	return String("");
}

ShipType getShipType(String& s)
{
	auto types = Dictionary<String, ShipType>();

	types.add(String("Pinnace"), ShipType::Pinnace);
	types.add(String("Sloep"), ShipType::Sloep);
	types.add(String("Brigg"), ShipType::Brigg);
	types.add(String("Barque"), ShipType::Barque);
	types.add(String("Korvet"), ShipType::Korvet);
	types.add(String("Fluyt"), ShipType::Fluyt);
	types.add(String("Fregat"), ShipType::Fregat);
	types.add(String("Galjoen"), ShipType::Galjoen);
	types.add(String("Handelsfluyt"), ShipType::Handelsfluyt);
	types.add(String("Caravel"), ShipType::Caravel);
	types.add(String("Carrack"), ShipType::Carrack);
	types.add(String("Oorlogsgaljoen"), ShipType::Oorlogsgaljoen);
	types.add(String("Ship of the Line"), ShipType::Ship_of_the_Line);

	return types.get(s);
}
