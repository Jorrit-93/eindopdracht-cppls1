#include "ship_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const ShipType ship_type)
{
	switch (ship_type)
	{
	case ShipType::Pinnace:
		return os << "Pinnace";
	case ShipType::Sloep:
		return os << "Sloep";
	case ShipType::Brigg:
		return os << "Brigg";
	case ShipType::Barque:
		return os << "Barque";
	case ShipType::Korvet:
		return os << "Korvet";
	case ShipType::Fluyt:
		return os << "Fluyt";
	case ShipType::Fregat:
		return os << "Fregat";
	case ShipType::Galjoen:
		return os << "Galjoen";
	case ShipType::Handelsfluyt:
		return os << "Handelsfluyt";
	case ShipType::Caravel:
		return os << "Caravel";
	case ShipType::Carrack:
		return os << "Carrack";
	case ShipType::Oorlogsgaljoen:
		return os << "Oorlogsgaljoen";
	case ShipType::Ship_of_the_Line:
		return os << "Ship of the Line";
	}
	return os;
}

String* shipTypeToString(const ShipType ship_type)
{
	switch (ship_type)
	{
	case ShipType::Pinnace:
		return new String("Pinnace");
	case ShipType::Sloep:
		return new String("Sloep");
	case ShipType::Brigg:
		return new String("Brigg");
	case ShipType::Barque:
		return new String("Barque");
	case ShipType::Korvet:
		return new String("Korvet");
	case ShipType::Fluyt:
		return new String("Fluyt");
	case ShipType::Fregat:
		return new String("Fregat");
	case ShipType::Galjoen:
		return new String("Galjoen");
	case ShipType::Handelsfluyt:
		return new String("Handelsfluyt");
	case ShipType::Caravel:
		return new String("Caravel");
	case ShipType::Carrack:
		return new String("Carrack");
	case ShipType::Oorlogsgaljoen:
		return new String("Oorlogsgaljoen");
	case ShipType::Ship_of_the_Line:
		return new String("Ship of the Line");
	}
	return nullptr;
}

ShipType getShipType(String* s)
{
	auto types = Dictionary<String, ShipType>();

	types.add(new String("Pinnace"), ShipType::Pinnace);
	types.add(new String("Sloep"), ShipType::Sloep);
	types.add(new String("Brigg"), ShipType::Brigg);
	types.add(new String("Barque"), ShipType::Barque);
	types.add(new String("Korvet"), ShipType::Korvet);
	types.add(new String("Fluyt"), ShipType::Fluyt);
	types.add(new String("Fregat"), ShipType::Fregat);
	types.add(new String("Galjoen"), ShipType::Galjoen);
	types.add(new String("Handelsfluyt"), ShipType::Handelsfluyt);
	types.add(new String("Caravel"), ShipType::Caravel);
	types.add(new String("Carrack"), ShipType::Carrack);
	types.add(new String("Oorlogsgaljoen"), ShipType::Oorlogsgaljoen);
	types.add(new String("Ship of the Line"), ShipType::Ship_of_the_Line);

	return types.get(s);
}
