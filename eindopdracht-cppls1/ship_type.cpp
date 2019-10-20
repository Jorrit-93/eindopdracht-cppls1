#include "ship_type.h"

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
		}
		return os;
	}
}
