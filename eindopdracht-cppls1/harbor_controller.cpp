# include "harbor_controller.h"
#include "game_controller.h"
#include "parser.h"

HarborController::HarborController(GameController& game)
	: view(new HarborView()), game(game), harbor_builder(new HarborBuilder())
{
	
}

HarborController::~HarborController()
{
	delete view;
	delete harbor_builder;
	delete harbor;
}

void HarborController::instantiate(const HarborName name)
{
	harbor = harbor_builder->createHarbor(name);
}

void HarborController::enter()
{
	game.generalInfo();
	auto options = Array<String>(6);
	options.add(String("koop goederen"));
	options.add(String("koop kannonen"));
	options.add(String("koop schip"));
	options.add(String("repareer schip"));
	options.add(String("vaar weg"));
	options.add(String("stop"));

	//view->printEnterHarborOutput();
	const auto input = view->getInput(&options);

	switch(input)
	{
		case 1:
			view->printStockOutput(*harbor->stocks);
			buyStock();
			break;
		case 2:
			//view->printCannonOutput();
			//buy cannons
			break;
		case 3:
			//view->printShipOutput();
			//buy ship
			break;
		case 4:
			view->printRepairOutput();
			repairShip();
			break;
		case 5:
			view->printBonVoyageOutput(*harbor->distances);
			bonVoyage();
			break;
		case 6:
			game.quit();
			break;
		default:
			throw;
	}
}

void HarborController::exit()
{
	delete harbor;
}

void HarborController::buyStock()
{
	//const auto stocks = harbor->stocks->getKeys();
	//const auto stocks_amount = harbor->stocks->getValues();
	//auto options = Array<String>(stocks.count() + 1);

	//for (int i = 0; i < stocks.count(); i++)
	//{
	//	options.add(new String(*stockTypeToString(stocks.getAt(i).getType())));
	//}
	//options.add(new String("Terug naar de haven"));

	//const auto input = view->getInput(&options);
	//
	//if (input == options.count())
	//{
	//	return;
	//}

	//for (int i = 0; i < stocks.count(); i++)
	//{
	//	if (stocks.getAt(i)->getType() == getStockType(&options.getAt(input - 1)))
	//	{
	//		auto stock = stocks.getAt(i);
	//		const auto stock_amount = stocks_amount.getAt(i).getValue();
	//		auto max_amount = game.getGold() / stock->getPrice();

	//		if (max_amount > stock_amount)
	//		{
	//			max_amount = stock_amount;
	//		}
	//		if (max_amount > game.getShip().getCargoSpace())
	//		{
	//			max_amount = game.getShip().getCargoSpace();
	//		}
	//		
	//		const auto amount = view->getInputAmount(max_amount);

	//		stock = harbor->buyStock(stock->getType(), amount);
	//		game.addGold(-(stock->getPrice() * amount));
	//		game.addStock(stock, amount);
	//	}
	//}
}

void HarborController::repairShip()
{
	
}

void HarborController::bonVoyage()
{
	auto harbors = harbor->distances->getKeys().toArray();
	auto options = new Array<String>(harbors.count() + 1);

	for(int i = 0; i < harbors.count(); i++)
	{
		if (harbors.getAt(i) != harbor->name)
		{
			options->add(harborNameToString(harbors.getAt(i)));
		}
	}
	auto returnOption = String("Terug naar de haven");
	options->add(&returnOption);

	const auto input = view->getInput(options);
	if (input == options->count())
	{
		return;
	}
	
	//auto destination = getHarborName(&options->getAt(input - 1));
	//auto distance = harbor->distances->get(destination);

	delete options;
	//move to sea
}


