#pragma once
#include "i_parse_strategy.h"
#include "string.h"
#include "s_result.h"

class Parser
{
public:
	Parser();
	~Parser();
	void getResult(const String& path);
	void setStrategy(const IParseStrategy& strategy);
	
private:
	IParseStrategy* strategy;
	void Open();
};

