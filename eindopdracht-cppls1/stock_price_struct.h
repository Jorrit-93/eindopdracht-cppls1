#pragma once
#include "harbor_name.h"
#include "dictionary.h"
#include "stock_type.h"

struct StockPriceStruct
{
public:
	HarborName name;
	Dictionary<StockType, int>* min_price = nullptr;
	Dictionary<StockType, int>* max_price = nullptr;

	StockPriceStruct() = default;
	~StockPriceStruct()
	{
		delete min_price;
		delete max_price;
	}

	//copy
	StockPriceStruct(const StockPriceStruct& other)
	{
		*this = other;
	}
	StockPriceStruct& operator=(const StockPriceStruct& other)
	{
		delete min_price;
		if (other.min_price)
		{
			min_price = new Dictionary<StockType, int>(*other.min_price);
		}
		
		delete max_price;
		if (other.max_price)
		{
			max_price = new Dictionary<StockType, int>(*other.max_price);
		}
		
		name = other.name;
		
		return *this;
	}

	//move
	StockPriceStruct(StockPriceStruct&& other) noexcept
	{
		*this = std::move(other);
	}
	StockPriceStruct& operator=(StockPriceStruct&& other) noexcept
	{
		delete min_price;
		min_price = other.min_price;
		other.min_price = nullptr;
		
		delete max_price;
		max_price = other.max_price;
		other.max_price = nullptr;
		
		name = other.name;
		
		return *this;
	}
};
