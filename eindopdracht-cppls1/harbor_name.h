#pragma once
#include <ostream>
#include "string.h"

enum class HarborName
{
	Roatan,
	Belize,
	Cayman,
	Evangelista,
	Trinidad,
	Port_Royale,
	Santiago,
	Port_au_prince,
	Santo_Domingo,
	Saint_Kitts,
	Santa_Lucia,
	Grenada,
	Port_of_Spain,
	Puerto_Santo,
	Margarita,
	Caracas,
	Puerto_Cabello,
	Curacao,
	Coro,
	Gibraltar,
	Maracaibo,
	Santa_Marta,
	Cartagena,
	Providence,
};

std::ostream& operator<<(std::ostream& os, HarborName harbor_name);

String* harborNameToString(HarborName harbor_name);
HarborName getHarborName(String* s);