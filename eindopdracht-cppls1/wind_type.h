#pragma once
#include <ostream>
#include "string.h"

enum class WindType
{
	geen,
	briesje,
	zwak,
	normaal,
	sterk,
	storm,
};

std::ostream& operator<<(std::ostream& os, WindType wind_type);

String* windTypeToString(WindType wind_type);
WindType getWindType(String& s);