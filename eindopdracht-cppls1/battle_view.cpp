#include "battle_view.h"
#include "pirate_ship.h"

void BattleView::printBattleOutput(IShip& pirate_ship) const
{
	std::cout << "Je bent in een gevecht beland met een ";
		// for(int i = 0; i < pirate_ship.getTraits()->count(); i ++)
		// {
		// 	std::cout << pirate_ship.getTraits()->getAt(i) << " ";
		// }
	std::cout << pirate_ship.getType() << " piratenship!" << std::endl;
	std::cout << "Het piratenschip heeft " << pirate_ship.getHP() << " HP" << std::endl;
	std::cout << "Wat wil je doen?" << std::endl;	
}
