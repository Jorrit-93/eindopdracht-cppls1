#include "game_controller.h"
#include "game_view.h"
#include "random.h"
#include <sstream>

GameController::GameController()
	: view(new GameView()), harbor_c(new HarborController(*this)), sea_c(new SeaController(*this)), battle_c(new BattleController(*this))
{
	ship_builder = new ShipBuilder();
	//initialize();
	//start();
}

GameController::~GameController()
{
	delete view;
	delete harbor_c;
	delete sea_c;
	delete battle_c;
	delete ship_builder;
	delete ship;
}

void GameController::initialize()
{
	setShip(ShipType::Pinnace);
	gold = 1000;
	//view->printStartOutput();
	//view->getInput();

	moveToHarbor(static_cast<HarborName>(Random::global()->randomInt(0, 23)));
}

void GameController::start()
{
	while (is_playing)
	{
		current_c->enter();
	}
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
	generalInfo();
	auto options = Array<String>(2);
	options.add(new String("ja"));
	options.add(new String("nee"));

	view->printRedoOutput();
	const auto input = view->getInput(&options);

	switch(input){
		case 1:
			initialize();
			break;
		case 2:
			is_playing = false;
			break;
		default:
			throw;
	}
}

void GameController::quit()
{
	generalInfo();
	auto options = Array<String>(2);
	options.add(new String("ja"));
	options.add(new String("nee"));
	
	view->printQuitOutput();
	const auto input = view->getInput(&options);

	switch(input)
	{
		case 1:
			is_playing = false;
			break;
		case 2:
			break;
		default:
			throw;
	}
}

void GameController::generalInfo() const
{
	view->clear();
	
	auto dictionary = Dictionary<String, String>();

	dictionary.add(new String("ship"), new String(shipTypeToString(ship->getType())->toCharArray()));
	
	std::stringstream str1;
	str1 << ship->getHP();
	dictionary.add(new String("hp") , new String(str1.str().c_str()));
	
	std::stringstream str2;
	str2 << gold;
	dictionary.add(new String("gold"), new String(str2.str().c_str()));
	
	std::stringstream str3;
	str3 << ship->getCargoSpace() - stocks->count();
	dictionary.add(new String("cargo space"), new String(str3.str().c_str()));
	
	view->printGeneralInfoOutput(dictionary);
}

void GameController::moveToHarbor(const HarborName name)
{
	harbor_c->instantiate(name);
	current_c = harbor_c;
}

void GameController::moveToSea()
{
	//sea_c->instantiate();
	current_c = sea_c;
}

void GameController::engageInBattle()
{
	battle_c->instantiate();
	current_c = battle_c;
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

void GameController::addStock(Stock* stock, int amount) const
{
	for(int i = 0; i < stocks->count(); i++)
	{
		if (stocks->getKeys().getAt(i).getType() == stock->getType())
		{
			amount += stocks->getValues().getAt(i);
			stocks->getKeys().removeAt(i);
			stocks->getValues().removeAt(i);
		}
	}
	stocks->add(stock, amount);
}

int GameController::getGold() const
{
	return gold;
}

Dictionary<Stock, int>* GameController::getStocks() const
{
	return stocks;
}

void GameController::setStocks(Dictionary<Stock, int>* stocks)
{
	delete stocks;
	this->stocks = stocks;
}
