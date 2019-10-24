#pragma once
#include "parse_state.h"
#include "stock_price_struct.h"

class StockPriceState : public ParseState<StockPriceStruct>
{
	List<StockPriceStruct>* parse(std::ifstream& stream) override;
};
