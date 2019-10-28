#include "game_controller.h"

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

void game()
{
	GameController();
}

int main()
{
	game();
	
	_CrtDumpMemoryLeaks();

	return 0;
}