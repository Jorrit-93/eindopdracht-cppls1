#pragma once
#include "s_result.h"
#include "string.h"

struct SGood : SResult
{
	String name;
	
	int maxPrice;
	int minPrice;

	int maxAmount;
	int minAmount;
};
