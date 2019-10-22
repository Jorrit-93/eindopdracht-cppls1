#pragma once
#include "turn_view.h"
#include "harbor_name.h"
#include "dictionary.h"
#include "stock_type.h"
#include "cannon_type.h"
#include "ship_type.h"

class HarborView : public TurnView
{
public:
	void printEnterHarborOutput(HarborName name);
	void printStockOutput(Dictionary<StockType, String*> stocks);
	void printCannonOutput(Dictionary<CannonType, String*> cannons);
	void printShipOutput(Dictionary<ShipType, String*> ships);
	void printRepairOutput();
	void printBonVoyageOutput(Dictionary<HarborName, int> destinations);
};
