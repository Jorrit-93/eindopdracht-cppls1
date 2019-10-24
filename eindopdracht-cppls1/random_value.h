#pragma once

class RandomValue
{
protected:
	int value = 0;
	int min_value = 0;
	int max_value = 0;

public:
	RandomValue() = default;
	RandomValue(int min_value, int max_value);

	virtual int getValue() const;
	virtual void addToValue(int add_value);
	virtual void setRandomValue();
};