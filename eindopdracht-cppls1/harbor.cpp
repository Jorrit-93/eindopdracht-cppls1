#include "harbor.h"
#include "ship.h"

Harbor::Harbor(HarborName name, Dictionary<HarborName, int>* distances, Dictionary<Cannon, RandomValue>* cannons, Dictionary<Stock, RandomValue>* stocks, Array<ShipType>* ships)
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

Stock* Harbor::buyStock(const StockType type, const int amount) const
{
	//for (int i = 0; i < stocks->count(); i++)
	//{
	//	const auto stock = stocks->getKeys().getAt(i);
	//	const auto stock_amount = stocks->getValues().getAt(i);
	//	if (stock.getType() == type)
	//	{
	//		//stock_amount.addToValue(-amount);
	//		return new Stock(*stock);
	//	}
	//}
	return nullptr;
}

Cannon* Harbor::buyCannon(const CannonType type, const int amount) const
{
	//for (int i = 0; i < cannons->count(); i++)
	//{
	//	const auto cannon = cannons->getKeys().getAt(i);
	//	const auto cannon_amount = cannons->getValues().getAt(i);
	//	if (cannon->getType() == type)
	//	{
	//		//cannon_amount.addToValue(-amount);
	//		return new Cannon(*cannon);
	//	}
	//}
	return nullptr;
}
