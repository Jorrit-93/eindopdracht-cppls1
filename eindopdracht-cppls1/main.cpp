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

int main()
{
	CityDistanceState* city_distance_state = new CityDistanceState();
	String* path = new String("afstand tussen steden.csv");
	
	Parser* parser = new Parser();
	parser->setState(*city_distance_state);
	parser->setPath(*path);
	parser->getResult();
	
	std::cout << "Hello World" << "\n";
}
