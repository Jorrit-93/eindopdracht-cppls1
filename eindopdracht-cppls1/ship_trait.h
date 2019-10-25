#pragma once
#include <ostream>
#include "string.h"

enum class ShipTrait
{
	klein,
	licht,
	log,
};

std::ostream& operator<<(std::ostream& os, ShipTrait ship_trait);

String* shipTraitToString(ShipTrait ship_trait);
ShipTrait getShipTrait(String& s);