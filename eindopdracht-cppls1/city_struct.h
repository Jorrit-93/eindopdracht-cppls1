#pragma once
#include "result_struct.h"
#include "string.h"
#include "dictionary.h"
#include "good_struct.h"

struct CityStruct : ResultStruct
{
	String name;

	Dictionary<String, int> distances;

	List<SGood> goods;
};
