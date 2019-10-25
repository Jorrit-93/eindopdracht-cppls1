#include "ship_trait.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const ShipTrait ship_trait)
{
	const auto string = shipTraitToString(ship_trait);
	os << string;
	delete string;
	return os;
}

String* shipTraitToString(const ShipTrait ship_trait)
{
	switch (ship_trait)
	{
	case ShipTrait::klein:
		return new String("klein");
	case ShipTrait::licht:
		return new String("licht");
	case ShipTrait::log:
		return new String("log");
	}
	return nullptr;
}

ShipTrait getShipTrait(String& s)
{
	auto types = Dictionary<String, ShipTrait>();

	types.add(String("klein"), ShipTrait::klein);
	types.add(String("licht"), ShipTrait::licht);
	types.add(String("log"), ShipTrait::log);

	return types.get(s);
}