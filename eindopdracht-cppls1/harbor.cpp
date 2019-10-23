#include "harbor.h"
#include "ship.h"

Harbor::Harbor(HarborName name, Dictionary<HarborName, int>* distances, Dictionary<Cannon*, RandomValue*>* cannons, Dictionary<Stock*, RandomValue*>* stocks, Array<ShipType>* ships)
	: name(name), distances(distances), cannons(cannons), stocks(stocks), ships(ships)
{
}

Harbor::~Harbor()
{
	delete distances;
	delete cannons;
	delete stocks;
	delete ships;
}
