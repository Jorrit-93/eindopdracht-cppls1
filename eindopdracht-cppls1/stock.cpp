#include "stock.h"

Stock::Stock(const StockType type, const int min_price, const int max_price)
	: type(type), price(new RandomValue(min_price, max_price))
{
	price->setRandomValue();
}

Stock::~Stock()
{
	delete price;
}

int Stock::getPrice() const
{
	return price->getValue();
}
