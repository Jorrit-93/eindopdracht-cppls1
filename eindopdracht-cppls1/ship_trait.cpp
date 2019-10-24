#include "ship_trait.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const ShipTrait ship_trait)
{
	switch (ship_trait)
	{
	case ShipTrait::klein:
		return os << "klein";
	case ShipTrait::licht:
		return os << "licht";
	case ShipTrait::log:
		return os << "log";
	}
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

ShipTrait getShipTrait(String* s)
{
	auto types = Dictionary<String, ShipTrait>();

	types.add(new String("klein"), ShipTrait::klein);
	types.add(new String("licht"), ShipTrait::licht);
	types.add(new String("log"), ShipTrait::log);

	return types.get(s);
}