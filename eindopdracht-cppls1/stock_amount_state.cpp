#include "stock_amount_state.h"
#include <fstream>
#include <iostream>

List<StockAmountStruct>* StockAmountState::parse(std::ifstream& stream)
{
	auto result = new List<StockAmountStruct>;

	removeFirstLines(stream);
	removeLine(stream);

	for (auto line = String(""); getLine(stream, line);)
	{
		const auto temp = &explode(line);
		auto stock_amount = StockAmountStruct();

		stock_amount.name = getHarborName(temp->getAt(0));

		stock_amount.min_amount = new Dictionary<StockType, int>();
		stock_amount.max_amount = new Dictionary<StockType, int>();
		for (int i = 1; i < temp->count(); i++)
		{
			const auto stock_type = static_cast<StockType>(i - 1);
			const auto amount = &explode(String(temp->getAt(i).toCharArray()), '-');

			stock_amount.min_amount->add(stock_type, atoi(amount->getAt(0).toCharArray()));
			stock_amount.max_amount->add(stock_type, atoi(amount->getAt(1).toCharArray()));

			delete amount;
		}

		delete temp;
		line.clear();
		result->add(stock_amount);
	}

	return result;
}
