#include "ship_trait.h"

std::ostream& operator<<(std::ostream& os, ShipTrait ship_trait)
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
}

ShipTrait getShipTrait(String* s)
{
	auto types = Dictionary<String*, ShipTrait>();

	types.add(new String("klein"), ShipTrait::klein);
	types.add(new String("licht"), ShipTrait::licht);
	types.add(new String("log"), ShipTrait::log);

	return types.get(s);
}
