#pragma once
#include "turn_view.h"
#include "wind_type.h"

struct Sea;

class SeaView : public TurnView
{
public:
	void printSeaOutput(const WindType& windType, const Sea& sea);
};
