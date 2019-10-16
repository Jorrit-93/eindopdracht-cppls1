#pragma once
#include "cannon.h"

class LightCannon : public Cannon
{
public:
	LightCannon();

	int getDamage() override;
};
