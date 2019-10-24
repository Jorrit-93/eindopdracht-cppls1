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

void HarborController::instantiateHarbor(const HarborName name)
{
	harbor = harbor_builder->createHarbor(name);
	enterHarbor();
}

void HarborController::enterHarbor() const
{
	auto options = Array<String*>(6);
	options.add(new String("koop goederen"));
	options.add(new String("koop kannonen"));
	options.add(new String("koop schip"));
	options.add(new String("repareer schip"));
	options.add(new String("vaar weg"));
	options.add(new String("stop"));

	//view->printEnterHarborOutput();
	const auto input = view->getInput(&options);

	switch(input)
	{
		case 1:
			//view->printStockOutput();
			//buy stock
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
			//repair ship
			break;
		case 5:
			game.engageInBattle();
			//view->printBonVoyageOutput();
			//game.moveToSea();
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

void HarborController::bonVoyage()
{
	//auto options = harbor->distances->getKeys();

/*	auto option1 = HarborName::Belize;
	auto options = Array<HarborName>(1);
	options.add(option1);
	const auto input = view->getInput<HarborName>(&options);*/ //IMPLEMENT LIST.TOARRAY();
}


