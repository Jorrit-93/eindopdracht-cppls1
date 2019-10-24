# include "harbor_controller.h"
#include "game_controller.h"
#include "parser.h"

HarborController::HarborController(GameController& game)
	: view(new HarborView()), game(game)
{
	harbor_builder = new HarborBuilder();
}

HarborController::~HarborController()
{
	delete view;
	delete harbor_builder;
	delete harbor;
}

void HarborController::instantiateHarbor(const HarborName name)
{
	harbor = harbor_builder->createHarbor(name);
	enterHarbor();
}

void HarborController::enterHarbor()
{
	auto option1 = String("koop goederen");
	auto option2 = String("koop kannonen");
	auto option3 = String("koop schip");
	auto option4 = String("repareer schip");
	auto option5 = String("vaar weg");
	auto option6 = String("stop");
	auto options = Array<String*>(6);
	options.add(&option1);
	options.add(&option2);
	options.add(&option3);
	options.add(&option4);
	options.add(&option5);
	options.add(&option6);

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

void HarborController::exitHarbor(HarborName name, int distance) const
{
	delete harbor;
}

void HarborController::buyStock()
{
	auto stocks = harbor->stocks->getKeys()->toArray();
	auto options = new Array<String*>(stocks.count() + 1);

	for (int i = 0; i < stocks.count(); i++)
	{
		options->add(stockTypeToString(stocks.getAt(i)->getType()));
	}
	auto returnOption = String("Terug naar de haven");
	options->add(&returnOption);

	const auto input = view->getInput(options);
	if (input == options->count())
	{
		enterHarbor();
		return;
	}

	Stock* stock = nullptr;
	int stock_amount;
	for (int i = 0; i < stocks.count(); i++)
	{
		if (stocks.getAt(i)->getType() == getStockType(options->getAt(input - 1)))
		{
			stock = harbor->stocks->getKeys()->getAt(i);
			stock_amount = harbor->stocks->getValues()->getAt(i)->getValue();
		}
	}

	int max_amount = game.getGold() / stock->getPrice();
	if (max_amount > stock_amount)
	{
		max_amount = stock_amount;
	}

	const auto amount = view->getInputAmount(max_amount);
	
	delete options;
	enterHarbor();
}

void HarborController::repairShip()
{
}

void HarborController::bonVoyage()
{
	auto harbors = harbor->distances->getKeys()->toArray();
	auto options = new Array<String*>(harbors.count() + 1);

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
		enterHarbor();
		return;
	}
	
	auto destination = getHarborName(options->getAt(input - 1));
	auto distance = harbor->distances->get(destination);

	delete options;
	//move to sea
}


