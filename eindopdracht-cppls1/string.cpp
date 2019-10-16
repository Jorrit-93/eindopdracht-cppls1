#include "string.h"

String::String()
{
	n_length = 0;
	n_string = new char[n_length + 1];
	n_string[n_length] = '\0';
}

String::~String()
{
	delete[] n_string;
}

//copy
String::String(const String& other)
{
	*this = other;
}
String& String::operator=(const String& other)
{
	n_length = other.n_length;
	delete[] n_string;
	n_string = new char[n_length + 1];
	for (int i = 0; i < n_length; i++)
	{
		n_string[i] = other.n_string[i];
	}
	n_string[n_length] = '\0';
	return *this;
}

//move
String::String(const char* input) noexcept
{
	*this = input;
}
String& String::operator=(const char* input) noexcept
{
	n_length = 0;
	while (input[n_length] != '\0')
	{
		n_length++;
	}
	delete[] n_string;
	n_string = new char[n_length + 1];
	for (int i = 0; i < n_length; i++)
	{
		n_string[i] = input[i];
	}
	n_string[n_length] = '\0';
	input = nullptr;
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
	delete[] s.n_string;
	char* input = new char[100];
	is.getline(input, 100);
	s.n_length = is.gcount() - 1;
	s.n_string = input;
	return is;
}
