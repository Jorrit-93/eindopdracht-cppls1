#pragma once
#include "list.h"
#include "result_struct.h"
#include "string.h"

class IParseState
{
public:
	virtual List<ResultStruct*>* parse(const String* content) = 0;	
};

