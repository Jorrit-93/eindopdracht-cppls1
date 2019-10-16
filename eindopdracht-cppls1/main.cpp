#include <iostream>
#include "list.h"
#include "dictionary.h"
#include "cannon.h"
#include "light_cannon.h"
#include "heavy_cannon.h"
#include "medium_cannon.h"
#include "ship_builder.h"

int main()
{
	auto attributes = new Array<ShipAttribute>(2);
	attributes->add(ShipAttribute::Small);
	attributes->add(ShipAttribute::Light);
	auto test = ShipBuilder().setType(ShipType::Brigg).setPrice(27000).setCargoSpace(250).setCannonAmount(16).setHP(140).setAttributes(attributes).build();
	std::cout << "" << "\n";
}
