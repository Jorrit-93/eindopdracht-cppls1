#pragma once
#include "harbor_name.h"

struct Battle
{
public:
	HarborName destination;
	int distance;

	Battle(HarborName destination, int distance);
};
