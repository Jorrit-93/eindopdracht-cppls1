#pragma once
#include "string.h"
#include "array.h"
#include <iostream>

class TurnView
{
public:
	virtual ~TurnView() = default;
	
	virtual String* getInput(Array<String*>* options);
	template<typename E> E getInput(Array<E>* options)
	{
		std::cout << '\n';
		int input;
		while (!options->contains((E)input))
		{
			for (int i = 0; i < options->count(); i++)
			{
				//std::cout << *options->getAt(i) << '\n';
			}
			std::cout << "Kies een optie..." << '\n';
			std::cin >> input;
			std::cout << '\n';
		}
		return options->get((E)input);
	}
	virtual void getInput();
};
