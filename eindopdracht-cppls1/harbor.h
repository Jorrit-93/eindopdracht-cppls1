#pragma once
#include "dictionary.h"
#include "cannon.h"
#include "stock.h"
#include "i_ship.h"
#include "harbor_name.h"

struct Harbor
{
public:
	HarborName name;
	Dictionary<HarborName, int>* distances;
	Dictionary<Cannon*, RandomValue*>* cannons;
	Dictionary<Stock*, RandomValue*>* stocks;
	Array<IShip*>* ships;

	Harbor(HarborName name);
	~Harbor();
};
