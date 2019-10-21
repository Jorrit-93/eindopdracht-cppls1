# include "sea_controller.h"
#include "game.h"
#include "random.h"

SeaController::SeaController(Game& game)
	: view(new SeaView()), game(game)
{

}

SeaController::~SeaController()
{
	delete view;
}

void SeaController::instantiateSea(const HarborName destination, const int distance)
{
	sea = new Sea(destination, distance);
	enterSea();
}

void SeaController::enterSea() const
{
	this->view->printSeaOutput(sea->wind_type);
	this->view->getInput();
	
	sea->distance = this->game.getShip().sail(sea->wind_type, sea->distance);
	if (this->game.getShip().hasSunk())
	{
		this->game.gameOver();
		return;
	}
	
	exitSea();
}

void SeaController::exitSea() const
{
	delete sea;
}

