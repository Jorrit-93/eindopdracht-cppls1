#include "harbor_name.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const HarborName harbor_name)
{
	switch (harbor_name)
	{
	case HarborName::Roatan:
		return os << "Roatan";
	case HarborName::Belize:
		return os << "Belize";
	case HarborName::Cayman:
		return os << "Cayman";
	case HarborName::Evangelista:
		return os << "Evangelista";
	case HarborName::Trinidad:
		return os << "Trinidad";
	case HarborName::Port_Royale:
		return os << "Port Royale";
	case HarborName::Santiago:
		return os << "Santiago";
	case HarborName::Port_au_prince:
		return os << "Port-au-prince";
	case HarborName::Santo_Domingo:
		return os << "Santo Domingo";
	case HarborName::Saint_Kitts:
		return os << "Saint Kitts";
	case HarborName::Santa_Lucia:
		return os << "Santa Lucia";
	case HarborName::Grenada:
		return os << "Grenada";
	case HarborName::Port_of_Spain:
		return os << "Port of Spain";
	case HarborName::Puerto_Santo:
		return os << "Puerto Santo";
	case HarborName::Margarita:
		return os << "Margarita";
	case HarborName::Caracas:
		return os << "Caracas";
	case HarborName::Puerto_Cabello:
		return os << "Puerto Cabello";
	case HarborName::Curacao:
		return os << "Curacao";
	case HarborName::Coro:
		return os << "Coro";
	case HarborName::Gibraltar:
		return os << "Gibraltar";
	case HarborName::Maracaibo:
		return os << "Maracaibo";
	case HarborName::Santa_Marta:
		return os << "Santa Marta";
	case HarborName::Cartagena:
		return os << "Cartagena";
	case HarborName::Providence:
		return os << "Providence";
	}
	return os;
}

String* harborNameToString(const HarborName harbor_name)
{
	switch (harbor_name)
	{
	case HarborName::Roatan:
		return new String("Roatan");
	case HarborName::Belize:
		return new String("Belize");
	case HarborName::Cayman:
		return new String("Cayman");
	case HarborName::Evangelista:
		return new String("Evangelista");
	case HarborName::Trinidad:
		return new String("Trinidad");
	case HarborName::Port_Royale:
		return new String("Port Royale");
	case HarborName::Santiago:
		return new String("Santiago");
	case HarborName::Port_au_prince:
		return new String("Port-au-prince");
	case HarborName::Santo_Domingo:
		return new String("Santo Domingo");
	case HarborName::Saint_Kitts:
		return new String("Saint Kitts");
	case HarborName::Santa_Lucia:
		return new String("Santa Lucia");
	case HarborName::Grenada:
		return new String("Grenada");
	case HarborName::Port_of_Spain:
		return new String("Port of Spain");
	case HarborName::Puerto_Santo:
		return new String("Puerto Santo");
	case HarborName::Margarita:
		return new String("Margarita");
	case HarborName::Caracas:
		return new String("Caracas");
	case HarborName::Puerto_Cabello:
		return new String("Puerto Cabello");
	case HarborName::Curacao:
		return new String("Curacao");
	case HarborName::Coro:
		return new String("Coro");
	case HarborName::Gibraltar:
		return new String("Gibraltar");
	case HarborName::Maracaibo:
		return new String("Maracaibo");
	case HarborName::Santa_Marta:
		return new String("Santa Marta");
	case HarborName::Cartagena:
		return new String("Cartagena");
	case HarborName::Providence:
		return new String("Providence");
	}
	return nullptr;
}

HarborName getHarborName(String* s)
{
	auto types = Dictionary<String*, HarborName>();

	types.add(new String("Roatan"), HarborName::Roatan);
	types.add(new String("Belize"), HarborName::Belize);
	types.add(new String("Cayman"), HarborName::Cayman);
	types.add(new String("Evangelista"), HarborName::Evangelista);
	types.add(new String("Trinidad"), HarborName::Trinidad);
	types.add(new String("Port Royale"), HarborName::Port_Royale);
	types.add(new String("Santiago"), HarborName::Santiago);
	types.add(new String("Port-au-prince"), HarborName::Port_au_prince);
	types.add(new String("Santo Domingo"), HarborName::Santo_Domingo);
	types.add(new String("Saint Kitts"), HarborName::Saint_Kitts);
	types.add(new String("Santa Lucia"), HarborName::Santa_Lucia);
	types.add(new String("Grenada"), HarborName::Grenada);
	types.add(new String("Port of Spain"), HarborName::Port_of_Spain);
	types.add(new String("Puerto Santo"), HarborName::Puerto_Santo);
	types.add(new String("Margarita"), HarborName::Margarita);
	types.add(new String("Caracas"), HarborName::Caracas);
	types.add(new String("Puerto Cabello"), HarborName::Puerto_Cabello);
	types.add(new String("Curacao"), HarborName::Curacao);
	types.add(new String("Coro"), HarborName::Coro);
	types.add(new String("Gibraltar"), HarborName::Gibraltar);
	types.add(new String("Maracaibo"), HarborName::Maracaibo);
	types.add(new String("Santa Marta"), HarborName::Santa_Marta);
	types.add(new String("Cartagena"), HarborName::Cartagena);
	types.add(new String("Providence"), HarborName::Providence);

	return types.get(s);
}
