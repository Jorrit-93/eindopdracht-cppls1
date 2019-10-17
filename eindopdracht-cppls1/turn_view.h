#pragma once
#include "string.h"
#include "array.h"
#include "dictionary.h"

class TurnView
{
public:
	virtual ~TurnView() = default;
	
	virtual void printGeneralOutput(Dictionary<String*, String*>* data);
	virtual String* getInput(Array<String*>* options);
	virtual void getInput();
};
