#include "harbor_distance_state.h"
#include <fstream>
#include <iostream>

List<HarborDistanceStruct*>* HarborDistanceState::parse(std::ifstream& stream)
{
	auto result = new List<HarborDistanceStruct*>;

	removeFirstLines(stream);
	removeLine(stream);

	for (const auto line = new String; getLine(stream, *line);)
	{
		auto temp = explode(*line);
		auto harbor_distance = new HarborDistanceStruct();

		harbor_distance->name = getHarborName(temp->getAt(0));

		harbor_distance->distances = new Dictionary<HarborName, int>();
		for (int i = 1; i < temp->count(); i++)
		{
			const auto harbor_name = static_cast<HarborName>(i - 1);
			const auto distance = atoi(temp->getAt(i)->toCharArray());
			if (harbor_name != harbor_distance->name)
			{
				harbor_distance->distances->add(harbor_name, distance);
			}
		}

		delete temp;
		result->add(harbor_distance);
	}

	return result;
}
