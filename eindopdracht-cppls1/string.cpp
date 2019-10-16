#include "string.h"

String::String()
{
	n_length = 0;
	n_string = new char[n_length];
	n_string[n_length] = '\0';
}

String& String::operator=(const String& s)
{
	n_length = s.n_length;
	delete[] n_string;
	n_string = new char[n_length];
	for (int i = 0; i < (n_length - 1); i++)
	{
		n_string[i] = s.n_string[i];
	}
	n_string[(n_length - 1)] = '\0';
	return *this;
}

bool operator==(const String& s1, const String& s2)
{
	if (s1.n_length == s2.n_length)
	{
		for (int i = 0; i < s1.n_length; i++)
		{
			if (s1.n_string[i] != s2.n_string[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.n_string;
	return os;
}

std::istream& operator>>(std::istream& is, String& s)
{
	s.n_length = is.gcount();
	char* input = new char[s.n_length];
	is.getline(input, s.n_length);

	s.n_string = input;
	delete[]input;
	
	return is;
}
