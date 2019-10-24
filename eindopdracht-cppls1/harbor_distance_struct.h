#pragma once
#include "harbor_name.h"
#include "dictionary.h"

struct HarborDistanceStruct
{
public:
	HarborName name;
	Dictionary<HarborName, int>* distances;

	~HarborDistanceStruct()
	{
		delete distances;
	}
};
