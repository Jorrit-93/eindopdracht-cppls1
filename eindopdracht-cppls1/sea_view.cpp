#include "sea_view.h"
#include "sea.h"

void SeaView::printSeaOutput(const WindType& windType, const Sea& sea)
{
	std::cout << "Je bent op zee, onderweg naar " << sea.destination << "! De huidige wind is " << windType << std::endl;
	std::cout << "Nog " << sea.distance << " stappen naar de eindbestemming." << std::endl;
}
