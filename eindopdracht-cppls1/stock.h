#pragma once
#include "stock_type.h"
#include "random_value.h"

class Stock
{
private:
	StockType type;
	RandomValue* price;

public:
	Stock() = default;
	Stock(StockType type, int min_price, int max_price);
	~Stock();

	StockType getType() const;
	int getPrice() const;
};
