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

StockType Stock::getType() const
{
	return type;
}

int Stock::getPrice() const
{
	return price->getValue();
}
