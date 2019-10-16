#pragma once
#include "cannon.h"

class MediumCannon : public Cannon
{
public:
	MediumCannon();

	int getDamage() override;
};
