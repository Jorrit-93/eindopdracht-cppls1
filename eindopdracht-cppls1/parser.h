#pragma once
#include "i_parse_state.h"
#include "string.h"
#include "result_struct.h"
#include "list.h"

class Parser
{
public:
	Parser();
	~Parser();
	List<ResultStruct*>* getResult();
	void setState(IParseState& state);
	void setPath(String& path);
	
private:
	IParseState* state;
	String* path;
	String* Open();
};

