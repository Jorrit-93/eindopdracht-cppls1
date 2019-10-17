#pragma once
#include "harbor_name.h"
#include "wind_type.h"

struct Sea
{
public:
	HarborName destination;
	int distance;
	WindType wind_type;

	Sea(HarborName destination, int distance);
};
