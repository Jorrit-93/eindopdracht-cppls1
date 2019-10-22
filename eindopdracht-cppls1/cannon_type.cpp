#include "cannon_type.h"

std::ostream& operator<<(std::ostream& os, CannonType cannon_type)
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
}

CannonType getCannonType(String* s)
{
	auto types = Dictionary<String*, CannonType>();

	types.add(new String("licht"), CannonType::licht);
	types.add(new String("medium"), CannonType::medium);
	types.add(new String("zwaar"), CannonType::zwaar);

	return types.get(s);
}
