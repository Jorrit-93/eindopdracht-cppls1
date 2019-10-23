#include "random.h"

Random* Random::instance = nullptr;

Random* Random::global()
{
	if (!instance)
	{
		instance = new Random();
	}
	return instance;
}

int Random::randomInt(int min_int, int max_int)
{
	const std::uniform_int_distribution<int> distribution(min_int, max_int);
	return distribution(device);
}

bool Random::chance(const int percentage)
{
	int r = randomInt(1, 100);
	
	return percentage <= r;
}
