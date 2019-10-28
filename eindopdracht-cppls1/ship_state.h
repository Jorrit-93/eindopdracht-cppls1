#pragma once
#include "parse_state.h"
#include "ship_struct.h"

class ShipState : public ParseState<ShipStruct*>
{
	List<ShipStruct*>* parse(std::ifstream& stream) override;
};

