#pragma once
#include "i_parse_state.h"
#include  "result_struct.h"


class CityDistanceState : IParseState
{
	List<ResultStruct*>* parse(const String& path) override;
};

