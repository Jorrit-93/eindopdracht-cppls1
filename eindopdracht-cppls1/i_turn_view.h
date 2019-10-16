#pragma once
#include "string.h"
#include "array.h"
#include "dictionary.h"

class ITurnView
{
public:
	virtual ~ITurnView() = default;
	
	virtual void printGeneralOutput(Dictionary<String*, String*>) = 0;
	virtual String* getInput(Array<String*>* option) = 0;
};
