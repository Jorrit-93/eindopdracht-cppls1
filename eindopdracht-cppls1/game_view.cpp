#include "game_view.h"
#include "ship_type.h"
#include <iostream>
#include <stdlib.h>

void GameView::printStartOutput()
{
	std::cout << "Hallo!" << '\n';
}

void GameView::printWinOutput()
{
	std::cout << "Gewonnen!" << '\n';
}

void GameView::printGameOverOutput()
{
	std::cout << "Game Over!" << '\n';
}

void GameView::printRedoOutput()
{
	std::cout << "Wil je nog een keer spelen?" << '\n';
}

void GameView::printQuitOutput()
{;
	std::cout << "Weet je zeker dat je wilt stoppen?" << '\n';
}

void GameView::printGeneralInfoOutput(Dictionary<String*, String*>* data)
{
	std::cout << "----------------------------------------------------------------------------------------------------" << '\n';
	for (int i = 0; i < data->count(); i++)
	{
		std::cout << *data->getKeys()->getAt(i) << " - " << *data->getValues()->getAt(i) << '\t';
	}
	std::cout << '\n';
	std::cout << "----------------------------------------------------------------------------------------------------" << '\n';
}

void GameView::clear()
{
	system("CLS");
}
