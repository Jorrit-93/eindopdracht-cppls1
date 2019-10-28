#pragma once
#include "harbor_name.h"
#include "dictionary.h"
#include "stock_type.h"

struct StockAmountStruct
{
public:
	HarborName name;
	Dictionary<StockType, int>* min_amount = nullptr;
	Dictionary<StockType, int>* max_amount = nullptr;

	StockAmountStruct() = default;
	~StockAmountStruct()
	{
		delete min_amount;
		delete max_amount;
	}

	//copy
	StockAmountStruct(const StockAmountStruct& other)
	{
		*this = other;
	}
	StockAmountStruct& operator=(const StockAmountStruct& other)
	{
		delete min_amount;
		if (other.min_amount)
		{
			min_amount = new Dictionary<StockType, int>(*other.min_amount);
		}
		
		delete max_amount;
		if (other.max_amount)
		{
			max_amount = new Dictionary<StockType, int>(*other.max_amount);
		}
		
		name = other.name;
		
		return *this;
	}

	//move
	StockAmountStruct(StockAmountStruct&& other) noexcept
	{
		*this = other;
	}
	StockAmountStruct& operator=(StockAmountStruct&& other) noexcept
	{
		delete min_amount;
		min_amount = other.min_amount;
		other.min_amount = nullptr;
		
		delete max_amount;
		max_amount = other.max_amount;
		other.max_amount = nullptr;
		
		name = other.name;
		
		return *this;
	}
};
