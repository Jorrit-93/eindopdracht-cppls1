#pragma once
#include "i_parse_state.h"

class CityDistanceState : public IParseState
{
	List<ResultStruct*>* parse(std::ifstream& stream) override;
};

