#include "game.h"
#include "game_view.h"
#include "random.h"

Game::Game()
	: view(new GameView()), in_harbor(new InHarbor(this)), on_sea(new OnSea(this)), in_battle(new InBattle(this))
{
	start();
}

Game::~Game()
{
	delete view;
	delete in_harbor;
	delete on_sea;
	delete in_battle;
}

void Game::start() const
{
	view->printStartOutput();
	view->getInput();
	moveToHarbor(static_cast<HarborName>(Random::global()->randomInt(1, 5)));
}

void Game::win() const
{
	view->printWinOutput();
}

void Game::gameOver() const
{
	view->printGameOverOutput();
	view->getInput(); // continue?
}

void Game::quit() const
{
	auto options = new Array<String*>(3);
	options->add(new String("ja"));
	options->add(new String("nee"));
	view->printQuitOutput();
	String test = *view->getInput(options);
}

void Game::moveToHarbor(const HarborName name) const
{
	in_harbor->moveToHarbor(name);
}

void Game::moveToSea() const
{
	on_sea->moveToSea();
}

void Game::engageInBattle() const
{
	in_battle->engageInBattle();
}
