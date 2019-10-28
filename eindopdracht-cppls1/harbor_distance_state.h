#pragma once
#include "parse_state.h"
#include "harbor_distance_struct.h"

class HarborDistanceState : public ParseState<HarborDistanceStruct*>
{
	List<HarborDistanceStruct*>* parse(std::ifstream& stream) override;
};

