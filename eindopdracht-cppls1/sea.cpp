#include "sea.h"
#include "random.h"

Sea::Sea(const HarborName destination, const int distance)
	: destination(destination), distance(distance)
{

}

void Sea::setRandomWindType()
{
	switch (Random::global()->randomInt(1, 20))
	{
	case 1:
	case 2:
		wind_type = WindType::geen;
		break;
	case 3:
	case 4:
		wind_type = WindType::briesje;
		break;
	case 5:
	case 6:
	case 7:
		wind_type = WindType::zwak;
		break;
	default:
		wind_type = WindType::normaal;
		break;
	case 18:
	case 19:
		wind_type = WindType::sterk;
		break;
	case 20:
		wind_type = WindType::storm;
		break;
	}
}
