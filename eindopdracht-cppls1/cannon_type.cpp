#include "cannon_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const CannonType cannon_type)
{
	switch (cannon_type)
	{
	case CannonType::licht:
		return os << "licht";
	case CannonType::medium:
		return os << "medium";
	case CannonType::zwaar:
		return os << "zwaar";
	}
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

CannonType getCannonType(String* s)
{
	auto types = Dictionary<String*, CannonType>();

	types.add(new String("licht"), CannonType::licht);
	types.add(new String("medium"), CannonType::medium);
	types.add(new String("zwaar"), CannonType::zwaar);

	return types.get(s);
}
