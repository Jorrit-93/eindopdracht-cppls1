#pragma once

class Cannon
{
protected:
	int max_damage;

public:
	virtual int getDamage() = 0;
};