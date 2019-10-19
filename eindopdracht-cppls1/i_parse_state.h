#pragma once
#include "list.h"
#include "result_struct.h"
#include "string.h"

class IParseState
{
public:
	virtual List<ResultStruct*>* parse(std::ifstream& stream) = 0;

protected:
	std::ifstream& getline(std::ifstream& stream, String& line, char delimeter = '\n');
};

