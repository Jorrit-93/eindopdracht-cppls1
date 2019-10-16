#include <iostream>
#include "random.h"

int main()
{
	std::cout << Random::global()->randomInt(0, 100) << "\n";
}
