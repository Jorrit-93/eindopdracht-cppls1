# include "harbor_controller.h"
#include "game_controller.h"

HarborController::HarborController(GameController& game)
	: view(new HarborView()), game(game)
{
	
}

HarborController::~HarborController()
{
	delete view;
}

void HarborController::moveToHarbor(const HarborName name)
{
	harbor = new Harbor(name);
	enterHarbor();
}

void HarborController::enterHarbor() const
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
