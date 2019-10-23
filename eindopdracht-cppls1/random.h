#pragma once
#include <random>

class Random
{
private:
	Random() = default;
	
	static Random* instance;
	std::random_device device;
	
public:
	static Random* global();
	int randomInt(int min_int, int max_int);
	bool chance(const int percentage);
};
