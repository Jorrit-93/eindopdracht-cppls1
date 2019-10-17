#pragma once
#include "result_struct.h"
#include "string.h"

struct SGood : ResultStruct
{
	String name;
	
	int maxPrice;
	int minPrice;

	int maxAmount;
	int minAmount;
};
