#pragma once
#include "string.h"
#include "array.h"

class TurnView
{
public:
	virtual ~TurnView() = default;
	
	virtual int getInput(Array<String*>* options);
	virtual void getInput();
};
