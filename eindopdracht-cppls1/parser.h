#pragma once
#include "i_parse_strategy.h"
#include "string.h"
#include "s_result.h"

class Parser
{
public:
	Parser();
	~Parser();
	void getResult(String* path);
	void setStrategy(IParseStrategy* strategy);
	
private:
	IParseStrategy* strategy;
	void Open();
};

