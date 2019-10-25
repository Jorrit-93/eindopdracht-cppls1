#include "game_controller.h"

#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

//String& testFunc(Array<String>& test1)
//{
//	auto test2 = test1.getAt(0);
//	auto test3 = new String(test2);
//	delete test3;
//	return test1.getAt(0);
//}
//
//void testFunc2()
//{
//	auto test1 = new Array<String>(1);
//	test1->add(new String("test"));
//
//	auto test4 = &testFunc(*test1);
//
//	delete test1;
//}


void game()
{
	auto game = GameController();
}

int main()
{
	game();
	
	_CrtDumpMemoryLeaks();

	return 0;
}