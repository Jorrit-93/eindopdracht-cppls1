#include "stock_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const StockType stock_type)
{
	const auto string = stockTypeToString(stock_type);
	os << string;
	return os;
}

String stockTypeToString(const StockType stock_type)
{
	switch (stock_type)
	{
	case StockType::bakstenen:
		return String("bakstenen");
	case StockType::laken:
		return String("laken");
	case StockType::cacao:
		return String("cacao");
	case StockType::katoen:
		return String("katoen");
	case StockType::verfstof:
		return String("verfstof");
	case StockType::vis:
		return String("vis");
	case StockType::hennep:
		return String("hennep");
	case StockType::aardappels:
		return String("aardappels");
	case StockType::rum:
		return String("rum");
	case StockType::zout:
		return String("zout");
	case StockType::suiker:
		return String("suiker");
	case StockType::tabak:
		return String("tabak");
	case StockType::graan:
		return String("graan");
	case StockType::vlees:
		return String("vlees");
	case StockType::hout:
		return String("hout");
	}
	return String("");
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
