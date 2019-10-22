#include "turn_view.h"
#include <iostream>

String* TurnView::getInput(Array<String*>* options)
{
	std::cout << '\n';
	String input = "";
	while (!options->contains(&input))
	{
		for (int i = 0; i < options->count(); i++)
		{
			std::cout << *options->getAt(i) << '\n';
		}
		std::cout << "Kies een optie..." << '\n';
		std::cin >> input;
		std::cout << '\n';
	}
	return options->get(&input);
}

void TurnView::getInput()
{
	std::cout << "Druk op ENTER om verder te gaan..." << '\n';
	std::cin.get();
}
