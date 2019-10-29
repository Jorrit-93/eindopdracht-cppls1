#include "battle_controller.h"
#include "game_controller.h"
#include "random.h"
#include "light_ship.h"
#include "small_ship.h"
#include "heavy_ship.h"

BattleController::BattleController(GameController& game) : view(new BattleView()), game(game)
{
	
}

BattleController::~BattleController()
{
	delete view;
}

void BattleController::instantiate()
{
	switch(Random::global()->randomInt(0, 2))
	{
	case 0:
		pirate_ship = new LightShip(new PirateShip());
	case 1:
		pirate_ship = new PirateShip();
	case 2:
		pirate_ship = new HeavyShip(new PirateShip());
	}

	// Start the battle
	enter();
}

void BattleController::enter()
{
	while (!is_over)
	{
		// Initialize Options
		auto options = Array<String>(3);
		options.add(String("schiet"));
		options.add(String("vlucht"));
		options.add(String("geef over"));

		// Get input
		const auto input = view->getInput(&options);

		// Handle the input
		//switch (input)
		//{
		//case 1:
		//	game.getShip().shoot(*pirate_ship);

		//	if (pirate_ship->hasSunk())
		//		break;

		//	pirate_ship->shoot(game.getShip());

		//	break;
		//case 2:
		//	pirate_ship->shoot(game.getShip());

		//	if (game.getShip().hasFled(*pirate_ship))
		//	{
		//		exit();
		//	}

		//	break;
		//case 3:
		//	{
		//	const auto cargo = new Dictionary<Stock, int>();

		//	game.setStocks(cargo);

		//	exit();
		//	break;
		//	}
		//default:
		//	throw;
		//}
	}
}

void BattleController::exit()
{
	delete pirate_ship;
	is_over = true;
}
