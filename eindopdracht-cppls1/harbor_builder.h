#pragma once
#include "harbor_name.h"
#include "harbor.h"
#include "array.h"
#include "harbor_distance_struct.h"
#include "stock_amount_struct.h"
#include "stock_price_struct.h"
#include "i_ship.h"

class HarborBuilder {
private:
	HarborName name_def = HarborName::Roatan;
	Dictionary<HarborName, int>* distances_def = nullptr;
	Dictionary<Cannon*, RandomValue*>* cannons_def = nullptr;
	Dictionary<Stock*, RandomValue*>* stocks_def = nullptr;
	Array<IShip*>* ships_def = nullptr;

	List<HarborDistanceStruct*>* harbor_distance_structs = nullptr;
	List<StockAmountStruct*>* stock_amount_structs = nullptr;
	List<StockPriceStruct*>* stock_price_structs = nullptr;
	
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

	Harbor* build();
};
