#pragma once
#include "list.h"
#include "string.h"
#include <fstream>
#include <sstream>

template<typename T>
class ParseState
{
public:
	virtual List<T>* parse(std::ifstream& stream) = 0;

protected:
	static std::istream& getLine(std::istream& stream, String& line, char delimeter = '\n')
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
	
	static void removeLine(std::istream& stream, const char delimiter = '\n')
	{
		char ch;
		while (stream.get(ch)) {
			if (ch == delimiter)
				break;
		}
	}

	static void removeFirstLines(std:: istream& stream, const char indicator = '#')
	{
		char ch;
		while (stream.get(ch) && ch == indicator)
		{
			removeLine(stream);
		}
	}
	
	static List<String>* explode(const String& string, const char delimiter = ';')
	{
		auto results = new List<String>;
		auto stream = new std::stringstream(string.toCharArray());

		String s;

		while (!stream->eof(), getLine(*stream, s, delimiter))
		{
			if(!s.isEmpty())
			{
				results->add(new String(s));
			}
		}
		if (!s.isEmpty())
		{
			results->add(new String(s));
		}

		delete stream;

		return results;
	}
};

