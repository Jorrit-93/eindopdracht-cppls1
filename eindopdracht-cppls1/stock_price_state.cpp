#include "stock_price_state.h"
#include <fstream>
#include <iostream>

List<StockPriceStruct*>* StockPriceState::parse(std::ifstream& stream)
{
	auto result = new List<StockPriceStruct*>;

	removeFirstLines(stream);
	removeLine(stream);

	for (const auto line = new String; getLine(stream, *line);)
	{
		auto temp = explode(*line);
		auto stock_price = new StockPriceStruct();

		stock_price->name = getHarborName(temp->getAt(0));

		stock_price->min_price = new Dictionary<StockType, int>();
		stock_price->max_price = new Dictionary<StockType, int>();
		for (int i = 1; i < temp->count(); i++)
		{
			const auto stock_type = static_cast<StockType>(i - 1);
			const auto amount = explode(String(temp->getAt(i)->toCharArray()), '-');

			stock_price->min_price->add(stock_type, atoi(amount->getAt(0)->toCharArray()));
			stock_price->max_price->add(stock_type, atoi(amount->getAt(1)->toCharArray()));

			delete amount;
		}

		delete temp;
		result->add(stock_price);
	}

	return result;
}
