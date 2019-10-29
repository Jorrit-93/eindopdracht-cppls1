#include  "harbor_view.h"

void HarborView::printEnterHarborOutput(HarborName name) const
{
	std::cout << '\n';
	std::cout << "Welkom in " << name << "!" << '\n';
}

void HarborView::printBuyStockOutput(const Dictionary<StockType, int>& stocks) const
{
	std::cout << '\n';
	std::cout << "Dit zijn alle goederen die je kunt kopen:" << '\n';
	std::cout << '\n';
	for (int i = 0; i < stocks.count(); i++)
	{
		std::cout << stocks.getKeyAt(i) << " - " << stocks.getValueAt(i) << '\n';
	}
}

void HarborView::printSellCargoOutput(const Dictionary<StockType, int>& stocks) const
{
	std::cout << '\n';
	std::cout << "Dit zijn alle goederen die je kunt verkopen:" << '\n';
	std::cout << '\n';
	for (int i = 0; i < stocks.count(); i++)
	{
		std::cout << stocks.getKeyAt(i) << " - " << stocks.getValueAt(i) << '\n';
	}
}

void HarborView::printBuyCannonOutput(const Dictionary<CannonType, int>& cannons) const
{
	std::cout << '\n';
	std::cout << "Dit zijn alle kannonen die je kunt kopen:" << '\n';
	std::cout << '\n';
	for (int i = 0; i < cannons.count(); i++)
	{
		std::cout << cannons.getKeyAt(i) << " - " << cannons.getValueAt(i) << '\n';
	}
}

void HarborView::printSellCannonOutput() const
{
	std::cout << '\n';
	std::cout << "Dit zijn alle kannonen die je kunt verkopen:" << '\n';
}

void HarborView::printBuyShipOutput(const Array<ShipType>& ships) const
{
	std::cout << '\n';
	std::cout << "Dit zijn alle schepen die hier te koop zijn:" << '\n';
	std::cout << '\n';
	for (int i = 0; i < ships.count(); i++)
	{
		std::cout << ships.getAt(i) << '\n';
	}
}

void HarborView::printRepairOutput() const
{
	std::cout << '\n';
	std::cout << "Laat weten voor hoeveel goud je je ship wilt laten repareren" << '\n';
}

void HarborView::printBonVoyageOutput(const Dictionary<HarborName, int>& destinations) const
{
	std::cout << '\n';
	std::cout << "Ik zie dat je de haven wilt verlaten. Kies een bestemming en bon voyage!" << '\n';
	std::cout << '\n';
	for (int i = 0; i < destinations.count(); i++)
	{
		std::cout << destinations.getKeyAt(i) << " - " << destinations.getValueAt(i) << '\n';
	}
}
