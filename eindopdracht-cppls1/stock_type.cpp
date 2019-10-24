#include "stock_type.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const StockType stock_type)
{
	switch (stock_type)
	{
	case StockType::bakstenen:
		return os << "bakstenen";
	case StockType::laken:
		return os << "laken";
	case StockType::cacao:
		return os << "cacao";
	case StockType::katoen:
		return os << "katoen";
	case StockType::verfstof:
		return os << "verfstof";
	case StockType::vis:
		return os << "vis";
	case StockType::hennep:
		return os << "hennep";
	case StockType::aardappels:
		return os << "aardappels";
	case StockType::rum:
		return os << "rum";
	case StockType::zout:
		return os << "zout";
	case StockType::suiker:
		return os << "suiker";
	case StockType::tabak:
		return os << "tabak";
	case StockType::graan:
		return os << "graan";
	case StockType::vlees:
		return os << "vlees";
	case StockType::hout:
		return os << "hout";
	}
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

StockType getStockType(String* s)
{
	auto types = Dictionary<String, StockType>();

	types.add(new String("bakstenen"), StockType::bakstenen);
	types.add(new String("laken"), StockType::laken);
	types.add(new String("cacao"), StockType::cacao);
	types.add(new String("katoen"), StockType::katoen);
	types.add(new String("verfstof"), StockType::verfstof);
	types.add(new String("vis"), StockType::vis);
	types.add(new String("hennep"), StockType::hennep);
	types.add(new String("aardappels"), StockType::aardappels);
	types.add(new String("rum"), StockType::rum);
	types.add(new String("zout"), StockType::zout);
	types.add(new String("suiker"), StockType::suiker);
	types.add(new String("tabak"), StockType::tabak);
	types.add(new String("graan"), StockType::graan);
	types.add(new String("vlees"), StockType::vlees);
	types.add(new String("hout"), StockType::hout);

	return types.get(s);
}
