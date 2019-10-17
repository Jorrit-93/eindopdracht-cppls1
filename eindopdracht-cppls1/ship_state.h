#pragma once
#include "i_parse_state.h"

class ShipState : public IParseState
{
	List<ResultStruct*>* parse(const String& path) override;
};

