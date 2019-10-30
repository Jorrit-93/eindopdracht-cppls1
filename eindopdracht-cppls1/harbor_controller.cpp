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
	
	auto options = Array<String>(8);
	options.add(String("koop goederen"));
	options.add(String("verkoop goederen"));
	options.add(String("koop kannonen"));
	options.add(String("verkoop kannonen"));
	options.add(String("koop schip"));
	options.add(String("repareer schip"));
	options.add(String("vaar weg"));
	options.add(String("stop"));

	view->printEnterHarborOutput(harbor->name);
	const auto input = view->getInput(&options);

	switch(input)
	{
		case 1:
			buyStock();
			break;
		case 2:
			sellStock();
			break;
		case 3:
			buyCannon();
			break;
		case 4:
			sellCannon();
			break;
		case 5:
			buyShip();
			break;
		case 6:
			repairShip();
			break;
		case 7:
			bonVoyage();
			break;
		case 8:
			game.quit();
			break;
		default:
			throw;
	}
}

void HarborController::exit()
{
	delete harbor;
	harbor = nullptr;
}

void HarborController::buyStock() const
{
	game.generalInfo();
	auto print_info = Dictionary<StockType, int>();
	for(int i = 0; i < harbor->stocks->count(); i++)
	{
		print_info.add(harbor->stocks->getKeyAt(i)->getType(), harbor->stocks->getValueAt(i)->getValue());
	}
	view->printBuyStockOutput(print_info);

	
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
			max_num.add(game.getShip().getCargoSpace() - game.getCargoSize());

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

			harbor->buyStock(stock->getType(), amount);
			game.addGold(-(stock->getPrice() * amount));
			game.addCargo(stock->getType(), amount);
		}
	}
}

void HarborController::sellStock() const
{
	game.generalInfo();
	auto print_info = Dictionary<StockType, int>();
	for (int i = 0; i < game.getCargo()->count(); i++)
	{
		print_info.add(game.getCargo()->getKeyAt(i), game.getCargo()->getValueAt(i));
	}
	view->printSellCargoOutput(print_info);

	const auto cargo = game.getCargo()->getKeys();
	auto options = Array<String>(cargo.count() + 1);

	for (int i = 0; i < cargo.count(); i++)
	{
		options.add(String(stockTypeToString(cargo.getAt(i))));
	}
	options.add(String("Terug naar de haven"));

	const auto input = view->getInput(&options);

	if (input == options.count())
	{
		return;
	}

	for (int i = 0; i < cargo.count(); i++)
	{
		if (cargo.getAt(i) == getStockType(options.getAt(input - 1)))
		{
			const auto choice = cargo.getAt(i);

			const auto amount = view->getInputAmount(game.getCargo()->getValueAt(i));

			const auto stocks = harbor->stocks->getKeys();
			for (int j = 0; j < stocks.count(); j++)
			{
				if (stocks.getAt(j)->getType() == choice)
				{
					harbor->stocks->getValueAt(j)->addToValue(amount);
					game.addGold(stocks.getAt(j)->getPrice() * amount);
					game.removeCargo(choice, amount);
				}
			}
		}
	}
}

void HarborController::buyCannon() const
{
	game.generalInfo();
	auto print_info = Dictionary<CannonType, int>();
	for (int i = 0; i < harbor->cannons->count(); i++)
	{
		print_info.add(harbor->cannons->getKeyAt(i)->getType(), harbor->cannons->getValueAt(i)->getValue());
	}
	view->printBuyCannonOutput(print_info);

	const auto cannons = harbor->cannons->getKeys();
	auto options = Array<String>(cannons.count() + 1);

	for (int i = 0; i < cannons.count(); i++)
	{
		if (!(game.getShip().getTraits()->contains(ShipTrait::klein) && cannons.getAt(i)->getType() == CannonType::zwaar))
		{
			options.add(String(cannonTypeToString(cannons.getAt(i)->getType())));
		}
	}
	options.add(String("Terug naar de haven"));

	const auto input = view->getInput(&options);

	if (input == options.count())
	{
		return;
	}

	for (int i = 0; i < cannons.count(); i++)
	{
		if (cannons.getAt(i)->getType() == getCannonType(options.getAt(input - 1)))
		{
			const auto choice = cannons.getAt(i);

			auto max_num = Array<int>(3);
			max_num.add(harbor->cannons->getValueAt(i)->getValue());
			max_num.add(game.getGold() / choice->getPrice());
			max_num.add(game.getShip().getCannons()->size() - game.getShip().getCannons()->count());

			int max_amount = INT_MAX;

			for (int i = 0; i < max_num.count(); i++)
			{
				int num = max_num.getAt(i);
				if (max_amount > num)
				{
					max_amount = num;
				}
			}
			
			const auto amount = view->getInputAmount(max_amount);

			for (int j = 0; j < amount; j++)
			{
				game.getShip().getCannons()->add(new Cannon(*choice));
			}
			game.addGold(-(choice->getPrice() * amount));
			harbor->cannons->getValueAt(i)->addToValue(-amount);
		}
	}
}

void HarborController::sellCannon() const
{
	game.generalInfo();
	view->printSellCannonOutput();

	const auto cannons = game.getShip().getCannons();
	auto options = Array<String>(cannons->count() + 1);

	for (int i = 0; i < cannons->count(); i++)
	{
		options.add(String(cannonTypeToString(cannons->getAt(i)->getType())));
	}
	options.add(String("Terug naar de haven"));

	const auto input = view->getInput(&options);

	if (input == options.count())
	{
		return;
	}

	for (int i = 0; i < cannons->count(); i++)
	{
		if (cannons->getAt(i)->getType() == getCannonType(options.getAt(input - 1)))
		{
			const auto choice = cannons->getAt(i);

			const auto harbor_cannons = harbor->cannons->getKeys();
			for (int j = 0; j < harbor_cannons.count(); j++)
			{
				if (harbor_cannons.getAt(j)->getType() == choice->getType())
				{
					harbor->cannons->getValueAt(j)->addToValue(1);
					game.addGold(harbor_cannons.getAt(j)->getPrice() / 2);
					game.getShip().getCannons()->removeAt(i);
				}
			}
		}
	}
}

void HarborController::buyShip() const
{
	game.generalInfo();
	auto print_info = Array<ShipType>(harbor->ships->count());
	for (int i = 0; i < print_info.size(); i++)
	{
		print_info.add(harbor->ships->getAt(i)->getType());
	}
	view->printBuyShipOutput(print_info);
	

	const auto ships = harbor->ships;
	auto options = Array<String>(ships->count() + 1);

	for (int i = 0; i < ships->count(); i++)
	{
		if (ships->getAt(i)->getPrice() <= game.getGold())
		{
			if (harbor->ships->getAt(i)->getType() > game.getShip().getType())
			{
				options.add(String(shipTypeToString(ships->getAt(i)->getType())));
			}
		}
	}
	options.add(String("Terug naar de haven"));

	const auto input = view->getInput(&options);

	if (input == options.count())
	{
		return;
	}

	game.addGold(-ships->getAt(input - 1)->getPrice() + game.getShip().getPrice());
	game.setShip(ships->getAt(input - 1)->getType());
	harbor->ships->removeAt(input - 1);
}

void HarborController::repairShip() const
{
	game.generalInfo();
	view->printRepairOutput();

	auto max_num = Array<int>(3);
	max_num.add(game.getGold());
	max_num.add((game.getShip().getHP() - game.getHP()) / 10);

	int max_amount = INT_MAX;

	for (int i = 0; i < max_num.count(); i++)
	{
		int num = max_num.getAt(i);
		if (max_amount > num)
		{
			max_amount = num;
		}
	}

	const auto amount = view->getInputAmount(max_amount);

	game.addGold(-amount);
	game.addHP(amount * 10);
}

void HarborController::bonVoyage() const
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

	game.moveToSea(destination, distance);
}


