#include "game_controller.h"

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main()
{
	GameController game = GameController();
	
	_CrtDumpMemoryLeaks();

	return 0;
}
