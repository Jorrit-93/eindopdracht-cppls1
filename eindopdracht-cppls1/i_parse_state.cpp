#include "i_parse_state.h"
#include <fstream>

std::ifstream& IParseState::getline(std::ifstream& stream, String& line, char delimeter)
{
	char ch;

	line = "";
	
	while (stream.get(ch)) {
		line += ch;
		if (ch == delimeter)
			break;
	}
	
	return stream;
}
