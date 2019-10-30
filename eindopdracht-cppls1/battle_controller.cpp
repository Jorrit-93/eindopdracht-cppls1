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
	delete pirate_ship;
	delete view;
}

void BattleController::instantiate()
{
	is_over = false;
	
	switch(Random::global()->randomInt(0, 2))
	{
		case 0:
			pirate_ship = new LightShip(new PirateShip());
			break;
		case 1:
			pirate_ship = new PirateShip();
			break;
		case 2:
			pirate_ship = new HeavyShip(new PirateShip());
			break;
	}
}

void BattleController::enter()
{
	while (!is_over)
	{
		// Show info
		game.generalInfo();
		view->printBattleOutput(*pirate_ship);
		
		// Initialize Options
		auto options = Array<String>(3);
		options.add(String(game.getShip().getCannons()->count() == 0 ? "schieten zonder kannonen" : "schiet" ));
		options.add(String("vlucht"));
		options.add(String("geef over"));
	
		// Get input
		const auto input = view->getInput(&options);
	
		// Handle the input
		switch (input)
		{
		case 1:
			game.getShip().shoot(*pirate_ship);
	
			if (pirate_ship->hasSunk())
			{
				is_over = true;
				break;
			}
	
			pirate_ship->shoot(game.getShip());
	
			break;
		case 2:
			pirate_ship->shoot(game.getShip());
	
			is_over = true;
	
			break;
		case 3:
			{
				for(int i = 0; i < game.getCargoSize(); i++)
				{
					game.removeCargo(game.getCargo()->getKeyAt(i), game.getCargo()->getValueAt(i));
				}
	
				is_over = true;
				break;
			}
		default:
			throw;
		}
	
		if (game.getShip().hasSunk())
		{
			game.gameOver();
			return;
		}
	}

	game.moveToSea();
}

void BattleController::exit()
{
	delete pirate_ship;
	pirate_ship = nullptr;
}
