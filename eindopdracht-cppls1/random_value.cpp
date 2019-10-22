#include "random_value.h"
#include "random.h"

RandomValue::RandomValue(int min_value, int max_value)
	: min_value(min_value), max_value(max_value)
{
	value = Random::global()->randomInt(min_value, max_value);
}

int RandomValue::getValue() const
{
	return value;
}

void RandomValue::setRandomValue()
{
	value = Random::global()->randomInt(min_value, max_value);
}
