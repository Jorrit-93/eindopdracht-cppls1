#pragma once
#include "string.h"
#include "array.h"
#include <iostream>

class TurnView
{
public:
	virtual ~TurnView() = default;
	
	virtual int getInput(Array<String*>* options);
	virtual int getInputAmount(int max_amount);
	virtual void getInput();
};
