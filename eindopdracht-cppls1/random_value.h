#pragma once

class RandomValue
{
protected:
	int value = 0;
	int min_value = 0;
	int max_value = 0;

	RandomValue(int min_value, int max_value);

	virtual int getValue() const = 0;
	virtual void setRandomValue() = 0;
};