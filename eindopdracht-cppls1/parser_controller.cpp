#include "parser_controller.h"
#include "ship_state.h"
#include "harbor_distance_state.h"
#include "stock_amount_state.h"
#include "stock_price_state.h"

ParserController::~ParserController()
{
	delete parser;
}

List<ShipStruct*>* ParserController::parseShips() const
{
	auto* ship_state = new ShipState();
	auto* ship_path = new String("resources/schepen.csv");
	parser->setPath(*ship_path);

	List<ShipStruct*>* result = parser->getResult<ShipStruct>(*ship_state);

	delete ship_state;
	delete ship_path;
	return result;
}

List<HarborDistanceStruct*>* ParserController::parseHarborDistances() const
{
	auto* harbor_distance_state = new HarborDistanceState();
	auto* harbor_distance_path = new String("resources/afstanden tussen steden.csv");
	parser->setPath(*harbor_distance_path);
	return parser->getResult<HarborDistanceStruct>(*harbor_distance_state);
}

List<StockAmountStruct*>* ParserController::parseStockAmount() const
{
	auto stock_amount_state = StockAmountState();
	auto stock_amount_path = String("resources/goederen hoeveelheid.csv");
	parser->setPath(stock_amount_path);
	return parser->getResult<StockAmountStruct>(stock_amount_state);
}

List<StockPriceStruct*>* ParserController::parseStockPrices() const
{
	auto stock_price_state = StockPriceState();
	auto stock_price_path = String("resources/goederen prijzen.csv");
	parser->setPath(stock_price_path);
	return parser->getResult<StockPriceStruct>(stock_price_state);
}
