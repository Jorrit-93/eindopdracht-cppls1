#include "stock_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const StockType stock_type)
{
	const auto string = stockTypeToString(stock_type);
	os << string;
	delete string;
	return os;
}

String* stockTypeToString(const StockType stock_type)
{
	switch (stock_type)
	{
	case StockType::bakstenen:
		return new String("bakstenen");
	case StockType::laken:
		return new String("laken");
	case StockType::cacao:
		return new String("cacao");
	case StockType::katoen:
		return new String("katoen");
	case StockType::verfstof:
		return new String("verfstof");
	case StockType::vis:
		return new String("vis");
	case StockType::hennep:
		return new String("hennep");
	case StockType::aardappels:
		return new String("aardappels");
	case StockType::rum:
		return new String("rum");
	case StockType::zout:
		return new String("zout");
	case StockType::suiker:
		return new String("suiker");
	case StockType::tabak:
		return new String("tabak");
	case StockType::graan:
		return new String("graan");
	case StockType::vlees:
		return new String("vlees");
	case StockType::hout:
		return new String("hout");
	}
	return nullptr;
}

StockType getStockType(String& s)
{
	auto types = Dictionary<String, StockType>();

	types.add(String("bakstenen"), StockType::bakstenen);
	types.add(String("laken"), StockType::laken);
	types.add(String("cacao"), StockType::cacao);
	types.add(String("katoen"), StockType::katoen);
	types.add(String("verfstof"), StockType::verfstof);
	types.add(String("vis"), StockType::vis);
	types.add(String("hennep"), StockType::hennep);
	types.add(String("aardappels"), StockType::aardappels);
	types.add(String("rum"), StockType::rum);
	types.add(String("zout"), StockType::zout);
	types.add(String("suiker"), StockType::suiker);
	types.add(String("tabak"), StockType::tabak);
	types.add(String("graan"), StockType::graan);
	types.add(String("vlees"), StockType::vlees);
	types.add(String("hout"), StockType::hout);

	return types.get(s);
}
