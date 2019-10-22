#pragma once
#include <ostream>
#include "string.h"
#include "dictionary.h"

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

WindType getWindType(String* s);