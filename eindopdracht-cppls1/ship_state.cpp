#include "ship_state.h"
#include "ship_struct.h"
#include <fstream>
#include <iostream>

List<ResultStruct*>* ShipState::parse(std::ifstream& stream)
{	
	
	for (String* line = new String; getline(stream, *line);)
	{
		std::cout << *line;
	}
	
	
	return nullptr;
}
