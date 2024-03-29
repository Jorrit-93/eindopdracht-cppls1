#pragma once
#include <ostream>
#include <istream>
#include "list.h"

class String
{
	
private:
	char* n_string;
	int n_length;

public:
	String();
	~String();

	//copy
	String(const String& other);
	String& operator=(const String& other);

	//move
	String(const char* input) noexcept;
	String& operator=(const char* input) noexcept;

	friend bool operator==(const String& s1, const String& s2);
	friend void operator+=(String& s, char c);

	char operator[](int index) const;
	char& operator[](int index);
	
	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);
	
	char* toCharArray() const;
	void pushBack(char input);
	void clear();
	int length() const;
	bool empty() const;
};
