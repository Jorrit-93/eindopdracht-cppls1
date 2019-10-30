#include "game_controller.h"

#include <crtdbg.h>
#include "random.h"
#define _CRTDBG_MAP_ALLOC

// void game()
// {
// 	
// }

int main()
{
	GameController();
	
	Random::deleteInstance();
	
	_CrtDumpMemoryLeaks();

	return 0;
}