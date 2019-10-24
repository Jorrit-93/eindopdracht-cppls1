#include  "harbor_view.h"

void HarborView::printStockOutput(const Dictionary<Stock*, RandomValue*>& stocks)
{
	for (int i = 0; i < stocks.count(); i++)
	{
		std::cout << stocks.getKeys()->getAt(i)->getType() << " - " << stocks.getValues()->getAt(i)->getValue() << std::endl;
	}
}

void HarborView::printRepairOutput()
{
}
