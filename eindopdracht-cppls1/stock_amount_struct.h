#pragma once
#include "harbor_name.h"
#include "dictionary.h"
#include "stock_type.h"

struct StockAmountStruct
{
public:
	HarborName name;
	Dictionary<StockType, int>* minAmount;
	Dictionary<StockType, int>* maxAmount;

	~StockAmountStruct() { delete minAmount; delete maxAmount; }
};
