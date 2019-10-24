# include "sea_controller.h"
#include "game_controller.h"
#include "random.h"

SeaController::SeaController(GameController& game)
	: view(new SeaView()), game(game)
{

}

SeaController::~SeaController()
{
	delete view;
	delete sea;
}

void SeaController::instantiate(const HarborName destination, const int distance)
{
	sea = new Sea(destination, distance);
	enter();
}

void SeaController::enter()
{
	this->view->printSeaOutput(sea->wind_type);
	this->view->getInput();
	
	sea->distance = this->game.getShip().sail(sea->wind_type, sea->distance);
	if (this->game.getShip().hasSunk())
	{
		this->game.gameOver();
		return;
	}
	
	exit();
}

void SeaController::exit()
{
	delete sea;
}

