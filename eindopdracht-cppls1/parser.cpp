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
	
	return this->state->parse(*this->path);
}

void Parser::setState(IParseState& state)
{
	this->state = &state;
}

void Parser::setPath(String& path)
{
	this->path = &path;
}

void Parser::Open()
{
	std::fstream fs;
	fs.open("afstanden tussen steden.csv", std::fstream::in | std::fstream::out | std::fstream::app);

	fs.close();
}
