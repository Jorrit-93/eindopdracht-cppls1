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
	void printEnterHarborOutput(HarborName name) const;
	void printBuyStockOutput(const Dictionary<StockType,int>& stocks) const;
	void printSellCargoOutput(const Dictionary<StockType, int>& stocks) const;
	void printBuyCannonOutput(const Dictionary<CannonType, int>& cannons) const;
	void printSellCannonOutput() const;
	void printBuyShipOutput(const Array<ShipType>& ships) const;
	void printRepairOutput() const;
	void printBonVoyageOutput(const Dictionary<HarborName, int>& destinations) const;
};
