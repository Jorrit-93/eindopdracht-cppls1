#pragma once
#include "i_turn_view.h"
#include "wind_type.h"

class OnSeaView : ITurnView
{
public:
	void printSeaOutput(WindType type);
};
