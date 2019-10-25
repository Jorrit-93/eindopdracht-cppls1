#pragma once

class RandomValue
{
private:
	int value = 0;
	int min_value = 0;
	int max_value = 0;

public:
	RandomValue() = default;
	~RandomValue() = default;
	RandomValue(int min_value, int max_value);

	int getValue() const;
	void addToValue(int add_value);
	void setRandomValue();
};