#include "wind_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, WindType wind_type)
{
	switch (wind_type)
	{
	case WindType::geen:
		return os << "geen";
	case WindType::briesje:
		return os << "briesje";
	case WindType::zwak:
		return os << "zwak";
	case WindType::normaal:
		return os << "normaal";
	case WindType::sterk:
		return os << "sterk";
	case WindType::storm:
		return os << "storm";
	}
}

WindType getWindType(String* s)
{
	auto types = Dictionary<String*, WindType>();

	types.add(new String("geen"), WindType::geen);
	types.add(new String("briesje"), WindType::briesje);
	types.add(new String("zwak"), WindType::zwak);
	types.add(new String("normaal"), WindType::normaal);
	types.add(new String("sterk"), WindType::sterk);
	types.add(new String("storm"), WindType::storm);

	return types.get(s);
}