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

std::ifstream& Parser::Open()
{	
	std::ifstream* ifs = new std::ifstream(this->path->toCharArray());

	return *ifs;
}
