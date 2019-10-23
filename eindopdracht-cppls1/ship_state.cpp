#include "ship_state.h"
#include "ship_struct.h"
#include <fstream>
#include <iostream>

List<ResultStruct*>* ShipState::parse(std::ifstream& stream)
{
	List<ShipStruct*>* result = new List<ShipStruct*>;
	List<String*>* temp = new List<String*>;

	removeFirstLine(stream);
	
	for (String* line = new String; getline(stream, *line);)
	{
		temp = explode(*line);

		ShipStruct* ship = new ShipStruct();
		ship->type = getShipType(temp->getAt(0));
		ship->price = atoi(temp->getAt(1)->toCharArray());
		ship->storage_capacity = atoi(temp->getAt(2)->toCharArray());
		ship->cannons = atoi(temp->getAt(3)->toCharArray());
		ship->health = atoi(temp->getAt(4)->toCharArray());
	
		
		std::cout << ship->type << std::endl;
		std::cout << ship->price << std::endl;
		std::cout << ship->storage_capacity << std::endl;
		std::cout << ship->cannons << std::endl;
		std::cout << ship->health << std::endl;
		std::cout << "---------" << std::endl;
	}

	delete temp;
	
	return nullptr;
}
