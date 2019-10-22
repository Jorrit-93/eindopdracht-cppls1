#pragma once
#include "turn_view.h"
#include "wind_type.h"

class SeaView : public TurnView
{
public:
	void printSeaOutput(WindType type);
};
