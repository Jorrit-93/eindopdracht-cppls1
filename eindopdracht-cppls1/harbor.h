#pragma once
#include "harbor_name.h"
#include "dictionary.h"
#include "cannon.h"
#include "stock.h"
#include "i_ship.h"

class Harbor
{
public:
	HarborName name;
	Dictionary<HarborName, int>* distances = nullptr;
	Dictionary<Cannon*, RandomValue*>* cannons = nullptr;
	Dictionary<Stock*, RandomValue*>* stocks = nullptr;
	Array<IShip*>* ships = nullptr;

	Harbor(HarborName name, Dictionary<HarborName, int>* distances, Dictionary<Cannon*, RandomValue*>* cannons, Dictionary<Stock*, RandomValue*>* stocks, Array<IShip*>* ships);
	~Harbor();
	Harbor(const Harbor& other) = delete;
	Harbor& operator=(const Harbor& other) = delete;
	Harbor(Harbor&& other) noexcept = delete;
	Harbor& operator=(Harbor&& other) noexcept = delete;

	void buyStock(StockType type, int amount) const;
	Cannon* buyCannon(CannonType type, int amount) const;
};
