#pragma once
#include "stock_type.h"
#include "random_value.h"

class Stock : RandomValue
{
private:
	StockType type;

public:
	Stock(StockType type, int min_price, int max_price);
	
	int getPrice() const;
	void setRandomPrice();
};
