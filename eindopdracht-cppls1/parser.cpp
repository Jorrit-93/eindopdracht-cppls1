#include "parser.h"
#include "ship_state.h"
#include <fstream>

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
	
	std::ifstream is;
	is.open(path->toCharArray(), std::ofstream::binary | std::ios::in);

	if (!is.is_open())
	{
		// Throw new exception
	}

	char c;
	while (is.get(c))
	{
		
	}

	return result;
}
