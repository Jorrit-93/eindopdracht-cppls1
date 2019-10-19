#pragma once
#include "list.h"
#include "result_struct.h"
#include "string.h"

class IParseState
{
public:
	virtual List<ResultStruct*>* parse(std::ifstream& stream) = 0;

protected:
	std::istream& getline(std::istream& stream, String& line, char delimeter = '\n');
	void removeFirstLine(std::istream& stream, char delimeter = '\n');
	List<String*>* explode(String& string, char delimeter = ';');
};

