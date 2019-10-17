#include "parser.h"
#include "ship_state.h"
#include <fstream>
#include <iostream>

Parser::Parser()
{
	
}

List<ResultStruct*>* Parser::getResult()
{	
	if (this->path == nullptr)
		return nullptr;
	
	return this->state->parse(this->Open());
}

void Parser::setState(IParseState& state)
{
	delete this->state;
	
	this->state = &state;
}

void Parser::setPath(String& path)
{
	this->path = &path;
}

String* Parser::Open()
{
	String* result = new String("");
	
	std::ifstream ifs("schepen.csv");
	//std::ifstream ifs(path->toCharArray());

	// if (!is.is_open())
	// {
	// 	return nullptr;
	// }

	char c;
	while (ifs.get(c))
	{
		*result += c;
	}

	return result;
}
