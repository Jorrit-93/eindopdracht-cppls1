#include "game_controller.h"

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main()
{
	GameController* game = new GameController();
	delete game;
	
	_CrtDumpMemoryLeaks();
	
	return 0;
}
