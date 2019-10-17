# include "harbor_controller.h"
#include "game.h"

HarborController::HarborController(Game& game)
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

	if (*input == option1)
	{
		//view->printStockOutput();
		//buy stock
		return;
	}
	if (*input == option2)
	{
		//view->printCannonOutput();
		//buy cannons
		return;
	}
	if (*input == option3)
	{
		//view->printShipOutput();
		//buy ship
		return;
	}
	if (*input == option4)
	{
		view->printRepairOutput();
		//repair ship
		return;
	}
	if (*input == option5)
	{
		//view->printBonVoyageOutput();
		game.moveToSea();
		return;
	}
	if (*input == option6)
	{
		game.quit();
		return;
	}
	throw; //option not valid
}

void HarborController::exitHarbor(HarborName name, int distance) const
{
	delete harbor;
}
