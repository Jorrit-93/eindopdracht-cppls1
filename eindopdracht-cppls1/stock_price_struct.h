#pragma once
#include "harbor_name.h"
#include "dictionary.h"
#include "stock_type.h"

struct StockPriceStruct
{
public:
	HarborName name;
	Dictionary<StockType, int>* min_price;
	Dictionary<StockType, int>* max_price;

	~StockPriceStruct() { delete min_price; delete max_price; }
};
