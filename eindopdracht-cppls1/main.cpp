#include <iostream>
#include "random.h"
#include "turn_view.h"
#include "battle_view.h"
#include "sea_view.h"
#include "harbor_view.h"
#include "game_controller.h"

#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main()
{
	GameController game = GameController();
	
	_CrtDumpMemoryLeaks();
	
	return 0;
}
