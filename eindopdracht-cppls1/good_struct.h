#pragma once
#include "result_struct.h"
#include "string.h"

struct GoodStruct : ResultStruct
{
	String name;
	
	int maxPrice;
	int minPrice;

	int maxAmount;
	int minAmount;
};
