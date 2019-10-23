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

void BattleController::initialize()
{
	switch(Random::global()->randomInt(0, 2))
	{
	case 0:
		pirate_ship = new LightShip(new PirateShip());
	case 1:
		pirate_ship = new SmallShip(new PirateShip());
	case 2:
		pirate_ship = new HeavyShip(new PirateShip());
	}

	// Start the battle
	enterBattle();
}

void BattleController::enterBattle() const
{
	while (!isOver)
	{
		// Initialize Options
		auto option1 = String("schiet");
		auto option2 = String("vlucht");
		auto option3 = String("geef over");
		auto options = Array<String*>(3);
		options.add(&option1);
		options.add(&option2);
		options.add(&option3);

		// Get input
		const auto input = view->getInput(&options);

		// Handle the input
		switch (input)
		{
		case 1:
			game.getShip().shoot(*pirate_ship);

			if (pirate_ship->hasSunk())
				break;

			pirate_ship->shoot(game.getShip());

			break;
		case 2:
			pirate_ship->shoot(game.getShip());

			if (game.getShip().hasFled(*pirate_ship))
			{
				exitBattle();
			}

			break;
		case 3:
			// maak de lading van het ship leeg
			break;
		default:
			throw;
		}
	}
}

void BattleController::exitBattle() const
{
	delete pirate_ship;
	//isover = false
}
