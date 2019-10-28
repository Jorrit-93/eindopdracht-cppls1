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
			repairShip();
			break;
		case 5:
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

void HarborController::buyStock() const
{
	game.generalInfo();
	view->printStockOutput(*harbor->stocks);
	
	const auto stocks = harbor->stocks->getKeys();
	auto options = Array<String>(stocks.count() + 1);

	for (int i = 0; i < stocks.count(); i++)
	{
		options.add(String(stockTypeToString(stocks.getAt(i)->getType())));
	}
	options.add(String("Terug naar de haven"));

	const auto input = view->getInput(&options);
	
	if (input == options.count())
	{
		return;
	}

	for (int i = 0; i < stocks.count(); i++)
	{
		if (stocks.getAt(i)->getType() == getStockType(options.getAt(input - 1)))
		{
			const auto stock = stocks.getAt(i);

			auto max_num = Array<int>(3);
			max_num.add(harbor->stocks->getValueAt(i)->getValue());
			max_num.add(game.getGold() / stock->getPrice());
			max_num.add(game.getShip().getCargoSpace());

			int max_amount = INT_MAX;

			for(int i = 0; i < max_num.count(); i++)
			{
				int num = max_num.getAt(i);
				if(max_amount > num)
				{
					max_amount = num;
				}
			}
			
			const auto amount = view->getInputAmount(max_amount);

			const auto new_stock = harbor->buyStock(stock->getType(), amount);
			game.addGold(-(stock->getPrice() * amount));
			game.addStock(new_stock, amount);
		}
	}
}

void HarborController::repairShip()
{
	game.generalInfo();
	view->printRepairOutput();
	
}

void HarborController::bonVoyage()
{
	game.generalInfo();
	view->printBonVoyageOutput(*harbor->distances);
	
	const auto harbors = harbor->distances->getKeys();
	auto options = Array<String>(harbors.count() + 1);

	for(int i = 0; i < harbors.count(); i++)
	{
		if (harbors.getAt(i) != harbor->name)
		{
			options.add(harborNameToString(harbors.getAt(i)));
		}
	}
	options.add(String("Terug naar de haven"));

	const auto input = view->getInput(&options);
	
	if (input == options.count())
	{
		return;
	}
	
	const auto destination = getHarborName(options.getAt(input - 1));
	const auto distance = harbor->distances->get(destination);

	//move to sea
}


