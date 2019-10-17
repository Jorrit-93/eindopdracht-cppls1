#include "game.h"
#include "game_view.h"
#include "random.h"
#include "ship.h"

Game::Game()
	: view(new GameView()), in_harbor(new InHarbor(*this)), on_sea(new OnSea(*this)), in_battle(new InBattle(*this))
{
	start();
}

Game::~Game()
{
	delete view;
	delete in_harbor;
	//delete on_sea;
	//delete in_battle;
}

void Game::start()
{
	setShip(ShipType::Pinnance);
	gold = 1000;
	view->printStartOutput();
	view->getInput();
	moveToHarbor(static_cast<HarborName>(Random::global()->randomInt(0, 23))); //determine size by harbor struct array
}

void Game::win()
{
	view->printWinOutput();
	view->getInput();
	redo();
}

void Game::gameOver()
{
	view->printGameOverOutput();
	view->getInput();
	redo();
}

void Game::redo()
{
	auto option1 = String("ja");
	auto option2 = String("nee");
	auto options = Array<String*>(2);
	options.add(&option1);
	options.add(&option2);

	view->printRedoOutput();
	const auto input = view->getInput(&options);

	if (*input == option1)
	{
		start();
		return;
	}
	if (*input == option2)
	{
		quit();
		return;
	}
	throw; //option not available
}

void Game::quit() const
{
	auto option1 = String("ja");
	auto option2 = String("nee");
	auto options = Array<String*>(2);
	options.add(&option1);
	options.add(&option2);
	
	view->printQuitOutput();
	const auto input = view->getInput(&options);

	if (*input == option1)
	{
		return;
	}
	if (*input == option2)
	{
		in_harbor->options();
		return;
	}
	throw; //option not available
}

void Game::generalInfo() const
{
	auto key1 = String("hp");
	auto key2 = String("gold");
	auto value1 = String("10");
	auto value2 = String(reinterpret_cast<const char*>(gold));
	auto dictionary = Dictionary<String*, String*>();
	dictionary.add(&key1, &value1);
	dictionary.add(&key2, &value2);
	view->printGeneralInfoOutput(&dictionary);
}

void Game::moveToHarbor(const HarborName name) const
{
	in_harbor->moveToHarbor(name);
}

void Game::moveToSea() const
{
	//on_sea->moveToSea();
}

void Game::engageInBattle() const
{
	//in_battle->engageInBattle();
}

void Game::setShip(ShipType type)
{
	delete ship;
	ship = new Ship(10); //set ship
}

void Game::addGold(const int value)
{
	gold += value;
}
