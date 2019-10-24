#include "turn_view.h"
#include <iostream>

int TurnView::getInput(Array<String>* options)
{
	std::cout << '\n';
	int input = 0;
	while (input < 1 || input > options->count() + 1)
	{
		for (int i = 0; i < options->count(); i++)
		{
			std::cout << "(" << i + 1 << ") " <<  options->getAt(i) << '\n';
		}
		std::cout << "Kies een optie..." << '\n';
		std::cin >> input;
		std::cout << '\n';
	}
	
	return input;
}

int TurnView::getInputAmount(int max_amount)
{
	std::cout << '\n';
	int input = max_amount + 1;
	while (input > max_amount)
	{
		std::cout << "Maximaal: " << max_amount << '\n';
		std::cout << "Kies een hoeveelheid..." << '\n';
		std::cin >> input;
		std::cout << '\n';
	}
	return input;
}

void TurnView::getInput()
{
	std::cout << "Druk op ENTER om verder te gaan..." << '\n';
	std::cin.get();
}
