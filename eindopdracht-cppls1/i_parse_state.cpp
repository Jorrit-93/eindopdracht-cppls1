#include "i_parse_state.h"
#include <fstream>
#include <sstream>

std::istream& IParseState::getline(std::istream& stream, String& line, char delimeter)
{
	char ch;

	line = "";
	
	while (stream.get(ch)) {
		
		if (ch == delimeter)
			break;

		line += ch;
	}
	
	return stream;
}

void IParseState::removeFirstLine(std::istream& stream, const char delimiter)
{
	char ch;

	while (stream.get(ch)) {
		if (ch == delimiter)
			break;
	}
}

List<String*>* IParseState::explode(String& string, const char delimiter)
{
	List<String*>* results = new List<String*>;
	std::stringstream* stream = new std::stringstream(string.toCharArray());

	String s;

	while (!stream->eof(), getline(*stream, s, delimiter) )
	{
		results->add(new String(s));
	}
	results->add(new String(s));
	
	delete stream;
	
	return results;
}
