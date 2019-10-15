#pragma once
#include "cannon.h"

class HeavyCannon : public Cannon
{
public:
	HeavyCannon();

	int getDamage() override;
};
