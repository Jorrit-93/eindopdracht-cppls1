#pragma once
#include "harbor_name.h"
#include "harbor.h"
#include "array.h"
#include "cannon_type.h"
#include "harbor_distance_struct.h"
#include "stock_amount_struct.h"
#include "stock_price_struct.h"
#include "ship_type.h"

class HarborBuilder {
private:
	HarborName name_def = HarborName::Roatan;
	Dictionary<HarborName, int>* distances_def = new Dictionary<HarborName, int>();
	Dictionary<Cannon*, RandomValue*>* cannons_def = new Dictionary<Cannon*, RandomValue*>();
	Dictionary<Stock*, RandomValue*>* stocks_def = new Dictionary<Stock*, RandomValue*>();
	Array<ShipType>* ships_def = new Array<ShipType>(0);

	List<HarborDistanceStruct*>* harbor_distance_structs;
	List<StockAmountStruct*>* stock_amount_structs;
	List<StockPriceStruct*>* stock_price_structs;

public:
	HarborBuilder();
	~HarborBuilder();

	Harbor* createHarbor(HarborName name);

private:
	HarborBuilder& setName(HarborName name);
	HarborBuilder& setDistances(Dictionary<HarborName, int>* distances);
	HarborBuilder& setCannons();
	HarborBuilder& setStocks(Dictionary<StockType, int>* min_amount_list, Dictionary<StockType, int>* max_amount_list, Dictionary<StockType, int>* min_price_list, Dictionary<StockType, int>* max_price_list);
	HarborBuilder& setShips();

	Harbor* build() const;
};
