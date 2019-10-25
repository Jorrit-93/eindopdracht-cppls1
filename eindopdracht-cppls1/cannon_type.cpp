#include "cannon_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const CannonType cannon_type)
{
	const auto string = cannonTypeToString(cannon_type);
	os << string;
	delete string;
	return os;
}

String* cannonTypeToString(const CannonType cannon_type)
{
	switch (cannon_type)
	{
	case CannonType::licht:
		return new String("licht");
	case CannonType::medium:
		return new String("medium");
	case CannonType::zwaar:
		return new String("zwaar");
	}
	return nullptr;
}

CannonType getCannonType(String& s)
{
	auto types = Dictionary<String, CannonType>();

	types.add(String("licht"), CannonType::licht);
	types.add(String("medium"), CannonType::medium);
	types.add(String("zwaar"), CannonType::zwaar);

	return types.get(s);
}
