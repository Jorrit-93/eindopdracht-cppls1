#pragma once
#include "string.h"
#include "parse_state.h"
#include "list.h"

class Parser
{
private:
	String* path = nullptr;
	
public:
	void setPath(String& path);

	template<typename  T>
	List<T>* getResult(ParseState<T>& state)
	{
		if (!path)
		{
			return nullptr;
		}
		std::ifstream* ifs = new std::ifstream(this->path->toCharArray());
 		List<T>* returnList = state.parse(*ifs);
		delete ifs;
		return returnList;
	}
};

