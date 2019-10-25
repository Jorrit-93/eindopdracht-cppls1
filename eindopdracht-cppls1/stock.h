#pragma once
#include "stock_type.h"
#include "random_value.h"

class Stock
{
private:
	StockType type;
	RandomValue* price = nullptr;

public:
	Stock() = default;
	Stock(StockType type, int min_price, int max_price);
	~Stock();
	Stock(const Stock& other);
	Stock& operator=(const Stock& other);
	Stock(Stock&& other) noexcept;
	Stock& operator=(Stock&& other) noexcept;

	StockType getType() const;
	int getPrice() const;
};
