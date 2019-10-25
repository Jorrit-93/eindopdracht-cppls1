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

//copy
Stock::Stock(const Stock& other)
{
	*this = other;
}
Stock& Stock::operator=(const Stock& other)
{
	delete price;
	price = new RandomValue(*other.price);
	type = other.type;
	return *this;
}

//move
Stock::Stock(Stock&& other) noexcept
{
	*this = other;
}
Stock& Stock::operator=(Stock&& other) noexcept
{
	delete price;
	price = other.price;
	other.price = nullptr;
	type = other.type;
	return *this;
}

StockType Stock::getType() const
{
	return type;
}

int Stock::getPrice() const
{
	return price->getValue();
}
