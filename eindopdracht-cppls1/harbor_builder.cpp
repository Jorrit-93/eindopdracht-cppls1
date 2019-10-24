#include "harbor_builder.h"
#include "parser_controller.h"
#include "random.h"

HarborBuilder::HarborBuilder()
{
	const auto parserController = ParserController();
	harbor_distance_structs = parserController.parseHarborDistances();
	stock_amount_structs = parserController.parseStockAmount();
	stock_price_structs = parserController.parseStockPrices();
}

HarborBuilder::~HarborBuilder()
{
	delete distances_def;
	delete cannons_def;
	delete stocks_def;
	delete ships_def;
	delete harbor_distance_structs;
	delete stock_amount_structs;
	delete stock_price_structs;
}

Harbor* HarborBuilder::createHarbor(HarborName name)
{
	int i = 0;
	auto harbor_distance = harbor_distance_structs->getAt(i);
	while (harbor_distance.name != name)
	{
		harbor_distance = harbor_distance_structs->getAt(i);
		i++;
	}

	int j = 0;
	auto stock_amount = stock_amount_structs->getAt(j);
	while (stock_amount.name != name)
	{
		stock_amount = stock_amount_structs->getAt(j);
		j++;
	}

	int k = 0;
	auto stock_price = stock_price_structs->getAt(k);
	while (stock_price.name != name)
	{
		stock_price = stock_price_structs->getAt(k);
		k++;
	}

	return setName(harbor_distance.name)
		.setDistances(harbor_distance.distances)
		.setCannons()
		.setStocks(stock_amount.minAmount, stock_amount.maxAmount, stock_price.min_price, stock_price.max_price)
		.setShips()
		.build();
}

HarborBuilder& HarborBuilder::setName(HarborName name)
{
	name_def = name;
	return *this;
}

HarborBuilder& HarborBuilder::setDistances(Dictionary<HarborName, int>* distances)
{
	delete distances_def;
	distances_def = distances;
	return *this;
}

HarborBuilder& HarborBuilder::setCannons()
{
	delete cannons_def;
	cannons_def = new Dictionary<Cannon, RandomValue>();
	cannons_def->add(new Cannon(CannonType::licht, 50, 2), new RandomValue(0, 5));
	cannons_def->add(new Cannon(CannonType::medium, 200, 4), new RandomValue(0, 3));
	cannons_def->add(new Cannon(CannonType::zwaar, 1000, 6), new RandomValue(0, 2));
	return *this;
}

HarborBuilder& HarborBuilder::setStocks(Dictionary<StockType, int>* min_amount_list, Dictionary<StockType, int>* max_amount_list, Dictionary<StockType, int>* min_price_list, Dictionary<StockType, int>* max_price_list)
{
	delete stocks_def;
	stocks_def = new Dictionary<Stock, RandomValue>();
	for (int i = 0; i < min_amount_list->getKeys().count(); i++)
	{
		const auto type = min_amount_list->getKeys().getAt(i);
		const auto min_amount = min_amount_list->get(type);
		const auto max_amount = max_amount_list->get(type);
		const auto min_price = min_price_list->get(type);
		const auto max_price = max_price_list->get(type);
		stocks_def->add(new Stock(type, min_price, max_price), new RandomValue(min_amount, max_amount));
	}
	return *this;
}

HarborBuilder& HarborBuilder::setShips()
{
	delete ships_def;
	ships_def = new Array<ShipType>(Random::global()->randomInt(0, 3));
	for (int i = 0; i < ships_def->size(); i++)
	{
		ships_def->add(static_cast<ShipType>(Random::global()->randomInt(0, 12)));
	}
	return *this;
}

Harbor* HarborBuilder::build() const
{
	return new Harbor(name_def, distances_def, cannons_def, stocks_def, ships_def);
}
