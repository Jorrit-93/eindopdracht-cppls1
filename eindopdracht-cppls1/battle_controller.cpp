#include "battle_controller.h"
#include "game.h"

BattleController::BattleController(Game& game)
	: view(new BattleView()), game(game)
{
	
}

BattleController::~BattleController()
{
	delete view;
}

void BattleController::engageInBattle(const HarborName destination, const int distance)
{
	battle = new Battle(destination, distance);
}

void BattleController::enterBattle() const
{
	
}

void BattleController::exitBattle() const
{
	
}
