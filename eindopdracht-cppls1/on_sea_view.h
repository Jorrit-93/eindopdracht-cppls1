#pragma once
#include "turn_view.h"
#include "wind_type.h"

class OnSeaView : public TurnView
{
public:
	void printSeaOutput(WindType type);
};
