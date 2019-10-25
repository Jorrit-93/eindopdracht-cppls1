#include "wind_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, WindType wind_type)
{
	const auto string = windTypeToString(wind_type);
	os << string;
	delete string;
	return os;
}

String* windTypeToString(WindType wind_type)
{
	switch (wind_type)
	{
	case WindType::geen:
		return new String("geen");
	case WindType::briesje:
		return new String("briesje");
	case WindType::zwak:
		return new String("zwak");
	case WindType::normaal:
		return new String("normaal");
	case WindType::sterk:
		return new String("sterk");
	case WindType::storm:
		return new String("storm");
	}
	return nullptr;
}

WindType getWindType(String& s)
{
	auto types = Dictionary<String, WindType>();

	types.add(String("geen"), WindType::geen);
	types.add(String("briesje"), WindType::briesje);
	types.add(String("zwak"), WindType::zwak);
	types.add(String("normaal"), WindType::normaal);
	types.add(String("sterk"), WindType::sterk);
	types.add(String("storm"), WindType::storm);

	return types.get(s);
}