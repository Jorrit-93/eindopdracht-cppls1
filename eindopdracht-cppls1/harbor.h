#pragma once
#include "harbor_name.h"
#include "dictionary.h"
#include "cannon.h"
#include "stock.h"
#include "ship_type.h"

struct Harbor
{
public:
	HarborName name;
	Dictionary<HarborName, int>* distances;
	Dictionary<Cannon*, RandomValue*>* cannons;
	Dictionary<Stock*, RandomValue*>* stocks;
	Array<ShipType>* ships;

	Harbor(HarborName name, Dictionary<HarborName, int>* distances, Dictionary<Cannon*, RandomValue*>* cannons,	Dictionary<Stock*, RandomValue*>* stocks, Array<ShipType>* ships);
	~Harbor();
};
