#include "stock.h"
#include "random.h"

Stock::Stock(const StockType type, const int min_price, const int max_price)
	: RandomValue(min_price, max_price), type(type)
{
	
}

int Stock::getPrice() const
{
	return getValue();
}

void Stock::setRandomPrice()
{
	setRandomValue();
}
