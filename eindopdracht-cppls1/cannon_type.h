#pragma once
#include <ostream>
#include "string.h"

enum class CannonType
{
	licht,
	medium,
	zwaar,
};

std::ostream& operator<<(std::ostream& os, CannonType cannon_type);

String cannonTypeToString(CannonType cannon_type);
CannonType getCannonType(String& s);