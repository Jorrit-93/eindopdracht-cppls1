#include <iostream>
#include "list.h"
#include "dictionary.h"
#include "cannon.h"
#include "parser.h"
#include "string.h"
#include "conio.h"
#include "ship_state.h"
#include "harbor_distance_state.h"
#include "stock_amount_state.h"
#include "stock_price_state.h"
#include "game.h"


int main()
{
	auto game = Game();
	////ShipState* state = new ShipState();
	////HarborDistanceState* state = new HarborDistanceState();
	////StockAmountState* state = new StockAmountState();
	//StockPriceState* state = new StockPriceState();
	//
	////String* path = new String("resources/schepen.csv");
	////String* path = new String("resources/afstanden tussen steden.csv");
	////String* path = new String("resources/goederen hoeveelheid.csv");
	//String* path = new String("resources/goederen prijzen.csv");
	//
	//Parser* parser = new Parser();
	//parser->setPath(*path);
	//
	////auto test = parser->getResult<ShipStruct>(*state);
	////auto test = parser->getResult<HarborDistanceStruct>(*state);
	////auto test = parser->getResult<StockAmountStruct>(*state);
	//auto test = parser->getResult<StockPriceStruct>(*state);

	return 0;
}
