#pragma once
#include <ostream>
#include "string.h"

enum class StockType
{
	bakstenen,
	laken,
	cacao,
	katoen,
	verfstof,
	vis,
	hennep,
	aardappels,
	rum,
	zout,
	suiker,
	tabak,
	graan,
	vlees,
	hout,
};

std::ostream& operator<<(std::ostream& os, StockType stock_type);

String* stockTypeToString(StockType stock_type);
StockType getStockType(String& s);