# include "in_harbor.h"
#include "game.h"

InHarbor::InHarbor(Game& game)
	: view(new InHarborView()), game(game)
{
	
}

InHarbor::~InHarbor()
{
	delete view;
}

void InHarbor::moveToHarbor(HarborName name) const
{
	//create harbor model
	options();
}

void InHarbor::options() const
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

	//printoptions
	const auto input = view->getInput(&options);

	if (*input == option1)
	{
		//buy stock
		return;
	}
	if (*input == option2)
	{
		//buy cannons
		return;
	}
	if (*input == option3)
	{
		//buy ship
		return;
	}
	if (*input == option4)
	{
		//repair ship
		return;
	}
	if (*input == option5)
	{
		//bon voyage
		return;
	}
	if (*input == option6)
	{
		game.quit();
		return;
	}
	throw; //option not available
}
