#include "ship_state.h"
#include <fstream>
#include <iostream>

List<ShipStruct*>* ShipState::parse(std::ifstream& stream)
{
	auto result = new List<ShipStruct*>;

	removeLine(stream);

	for (const auto line = new String; getLine(stream, *line);)
	{
		auto temp = explode(*line);
		auto ship = new ShipStruct();
		
		ship->type = getShipType(temp->getAt(0));
		
		ship->price = atoi(temp->getAt(1)->toCharArray());
		
		ship->storage_capacity = atoi(temp->getAt(2)->toCharArray());
		
		ship->cannons = atoi(temp->getAt(3)->toCharArray());
		
		ship->health = atoi(temp->getAt(4)->toCharArray());
		
		const auto traits = explode(String(temp->getAt(5)->toCharArray()), ',');
		ship->traits = new Array<ShipTrait>(traits->count());
		for (int i = 0; i < traits->count(); i++)
		{
			ship->traits->add(getShipTrait(traits->getAt(i)));
		}
		delete traits;

		delete temp;
		result->add(ship);
	}

	return result;
}
