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

void IParseState::removeFirstLine(std::istream& stream, char delimeter)
{
	char ch;

	while (stream.get(ch)) {
		if (ch == delimeter)
			break;
	}
}

List<String*>* IParseState::explode(String& string, char delimeter)
{
	List<String*>* result = new List<String*>;
	std::stringstream* stream = new std::stringstream(string.toCharArray());

	for (String* token = new String; getline(*stream, *token, delimeter); )
	{
		result->add(token);
	}

	delete stream;
	
	return result;
}
