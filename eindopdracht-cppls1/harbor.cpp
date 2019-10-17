#include "harbor.h"
#include "ship.h"

Harbor::Harbor(const HarborName name)
	: name(name)
{
	distances = new Dictionary<HarborName, int>();
	distances->add(HarborName::Belize, 10);
	cannons = new Dictionary<Cannon*, RandomValue*>();
	cannons->add(new Cannon(CannonType::licht, 50, 2), new RandomValue(0, 5));
	stocks = new Dictionary<Stock*, RandomValue*>();
	stocks->add(new Stock(StockType::aardappels, 25, 50), new RandomValue(10, 100));
	ships = new Array<IShip*>(1);
	ships->add(new Ship(10));
}

Harbor::~Harbor()
{
	delete distances;
	delete cannons;
	delete stocks;
	delete ships;
}
