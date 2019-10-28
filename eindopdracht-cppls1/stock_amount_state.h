#pragma once
#include "parse_state.h"
#include "stock_amount_struct.h"

class StockAmountState : public ParseState<StockAmountStruct*>
{
	List<StockAmountStruct*>* parse(std::ifstream& stream) override;
};

