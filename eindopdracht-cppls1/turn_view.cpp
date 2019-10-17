#include "turn_view.h"
#include <iostream>

void TurnView::printGeneralOutput(Dictionary<String*, String*>* data)
{
	std::cout << "----------------------------------------------------------------------------------------------------" << '\n';
	for (int i = 0; i < data->count(); i++)
	{
		std::cout << *data->getKeys()->getAt(i) << " - " << *data->getValues()->getAt(i) << '\t';
	}
	std::cout << '\n';
	std::cout << "----------------------------------------------------------------------------------------------------" << '\n';
}

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
		std::cout << "Please choose an option..." << '\n';
		std::cin >> input;
		std::cout << '\n';
	}
	return options->get(&input);
}

void TurnView::getInput()
{
	std::cout << "Press ENTER to continue..." << '\n';
	std::cin.get();
}
