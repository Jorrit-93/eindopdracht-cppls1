#pragma once
#include "harbor_name.h"
#include "dictionary.h"

struct HarborDistanceStruct
{
public:
	HarborName name;
	Dictionary<HarborName, int>* distances = nullptr;

	HarborDistanceStruct() = default;
	~HarborDistanceStruct()
	{
		delete distances;
	}

	//copy
	HarborDistanceStruct(const HarborDistanceStruct& other)
	{
		*this = other;
	}
	HarborDistanceStruct& operator=(const HarborDistanceStruct& other)
	{
		delete distances;
		distances = new Dictionary<HarborName, int>(*other.distances);
		name = other.name;
		return *this;
	}

	//move
	HarborDistanceStruct(HarborDistanceStruct&& other) noexcept
	{
		*this = other;
	}
	HarborDistanceStruct& operator=(HarborDistanceStruct&& other) noexcept
	{
		delete distances;
		distances = other.distances;
		other.distances = nullptr;
		name = other.name;
		return *this;
	}
};
