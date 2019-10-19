#include <iostream>
#include "list.h"
#include "dictionary.h"
#include "cannon.h"
#include "light_cannon.h"
#include "heavy_cannon.h"
#include "medium_cannon.h"
#include "parser.h"
#include "city_distance_state.h"
#include "string.h"
#include <conio.h>
#include "ship_state.h"


int main()
{
	ShipState* ship_state = new ShipState();
	String* path = new String("resources/schepen.csv");
	
	Parser* parser = new Parser();
	parser->setState(*ship_state);
	parser->setPath(*path);
	parser->getResult();
	
	std::cout << "Hello World" << "\n";

	return 0;
}
