#pragma once
#include "parser.h"
#include "ship_struct.h"
#include "harbor_distance_struct.h"
#include "stock_amount_struct.h"
#include "stock_price_struct.h"

class ParserController
{
private:
	Parser* parser = new Parser();
	
public:
	~ParserController();

	List<ShipStruct*>* parseShips() const;
	List<HarborDistanceStruct*>* parseHarborDistances() const;
	List<StockAmountStruct*>* parseStockAmount() const;
	List<StockPriceStruct*>* parseStockPrices() const;
};
