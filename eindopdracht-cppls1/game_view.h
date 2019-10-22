#pragma once
#include "turn_view.h"
#include "dictionary.h"

class GameView : public TurnView
{
public:
	void printStartOutput();
	void printWinOutput();
	void printGameOverOutput();
	void printRedoOutput();
	void printQuitOutput();
	void printGeneralInfoOutput(Dictionary<String*, String*>* data);
};
