#pragma once
#include "dictionary.h"
#include "cannon.h"
#include "stock.h"
#include "i_ship.h"
#include "harbor_name.h"

class Harbor
{
private:
	HarborName name;
	Dictionary<HarborName, int>* distances;
	Dictionary<Cannon*, RandomValue*>* cannons;
	Dictionary<Stock*, RandomValue*>* stocks;
	Array<IShip*>* ships;

public:
	Harbor(HarborName name);
	~Harbor();

	void addHarbor(Harbor* harbor, int distance);
	void addCannon(Cannon* stock);
	void addStock(Stock* stock);
	void addShip(IShip* ship);

	void moveToHarbor(HarborName harbor, int distance);
	void enterHarbor(HarborName harbor);
	Cannon* buyCannon(Cannon* cannon);
	Stock* buyStock(StockType* stock);
	IShip* buyShip(IShip* ship);
};
