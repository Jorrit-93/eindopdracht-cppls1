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
		std::cout << *temp->getAt(0) << std::endl;
		std::cout << *temp->getAt(1) << std::endl;
		std::cout << *temp->getAt(2) << std::endl;
		std::cout << *temp->getAt(3) << std::endl;
		std::cout << *temp->getAt(4) << std::endl;
		std::cout << *temp->getAt(5) << std::endl;
		std::cout << "---------" << std::endl;

		ShipStruct* ship = new ShipStruct();
	}

	delete temp;
	
	return nullptr;
}
