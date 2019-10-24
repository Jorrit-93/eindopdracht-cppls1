#include "game_controller.h"
#include "game_view.h"
#include "random.h"
#include "ship.h"

GameController::GameController():
	view(new GameView()),
	in_harbor(new HarborController(*this)),
	on_sea(new SeaController(*this)),
	in_battle(new BattleController(*this)),
	ship_builder(new ShipBuilder())
	
{
	start();
}

GameController::~GameController()
{
	delete view;
	delete in_harbor;
	delete on_sea;
	delete in_battle;
	delete ship_builder;
	delete ship;
}

void GameController::start()
{
	setShip(ShipType::Pinnace);
	gold = 1000;
	view->printStartOutput();
	view->getInput();
	moveToHarbor(static_cast<HarborName>(Random::global()->randomInt(0, 23))); //determine size by harbor struct array
}

void GameController::win()
{
	view->printWinOutput();
	view->getInput();
	redo();
}

void GameController::gameOver()
{
	view->printGameOverOutput();
	view->getInput();
	redo();
}

void GameController::redo()
{
	auto* options = new Array<String*>(2);
	options->add(new String("ja"));
	options->add(new String("nee"));

	view->printRedoOutput();
	const auto input = view->getInput(options);

	switch(input){
		case 1:
			start();
			break;
		case 2:
			quit();
			break;
		default:
			throw;
	}

	delete options;
}

void GameController::quit() const
{
	auto* options = new Array<String*>(2);
	options->add(new String("ja"));
	options->add(new String("nee"));
	
	view->printQuitOutput();
	const auto input = view->getInput(options);

	switch(input)
	{
		case 1:
			break;
		case 2:
			in_harbor->enterHarbor();
		default:
			throw;
	}

	delete options;
}

void GameController::generalInfo() const
{
	auto* dictionary = new Dictionary<String*, String*>();
	dictionary->add(new String("hp"), new String("10"));
	dictionary->add(new String("gold"), new String(reinterpret_cast<const char*>(gold)));
	
	view->printGeneralInfoOutput(dictionary);

	delete dictionary;
}

void GameController::moveToHarbor(const HarborName name) const
{
	in_harbor->enterHarbor();
}

void GameController::moveToSea() const
{
	on_sea->enterSea();
}

void GameController::engageInBattle() const
{
	in_battle->initialize();
}

IShip& GameController::getShip() const
{
	return *ship;
}

void GameController::setShip(ShipType type)
{
	delete ship;
	ship = ship_builder->createShip(type);
}

void GameController::addGold(const int value)
{
	gold += value;
}

Dictionary<Stock*, int>* GameController::getStocks() const
{
	return stocks;
}

void GameController::setStocks(Dictionary<Stock*, int>* stocks)
{
	delete stocks;
	this->stocks = stocks;
}
