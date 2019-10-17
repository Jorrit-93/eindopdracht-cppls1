#pragma once
#include "turn_view.h"

class GameView : public TurnView
{
public:
	void printStartOutput();
	void printWinOutput();
	void printGameOverOutput();
	void printQuitOutput();
};
