#pragma once
#include "harbor_name.h"

struct Battle
{
public:
	HarborName destination;
	int distance;

	Battle(HarborName destination, int distance);
	~Battle() = default;
	Battle(const Battle& other) = delete;
	Battle& operator=(const Battle& other) = delete;
	Battle(Battle&& other) noexcept = delete;
	Battle& operator=(Battle&& other) noexcept = delete;
};
