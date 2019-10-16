#pragma once
#include <ostream>
#include <istream>

class String
{
	
private:
	char* n_string;
	short n_length;

public:
	String();
	String(const char* input);
	String(const String& s);
	~String();

	String& operator=(const String& s);
	friend bool operator==(const String& s1, const String& s2);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
};
