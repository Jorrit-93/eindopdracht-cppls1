#include "harbor_name.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const HarborName harbor_name)
{
	const auto string = harborNameToString(harbor_name);
	os << string;
	return os;
}

String harborNameToString(const HarborName harbor_name)
{
	switch (harbor_name)
	{
	case HarborName::Roatan:
		return String("Roatan");
	case HarborName::Belize:
		return String("Belize");
	case HarborName::Cayman:
		return String("Cayman");
	case HarborName::Evangelista:
		return String("Evangelista");
	case HarborName::Trinidad:
		return String("Trinidad");
	case HarborName::Port_Royale:
		return String("Port Royale");
	case HarborName::Santiago:
		return String("Santiago");
	case HarborName::Port_au_prince:
		return String("Port-au-prince");
	case HarborName::Santo_Domingo:
		return String("Santo Domingo");
	case HarborName::Saint_Kitts:
		return String("Saint Kitts");
	case HarborName::Santa_Lucia:
		return String("Santa Lucia");
	case HarborName::Grenada:
		return String("Grenada");
	case HarborName::Port_of_Spain:
		return String("Port of Spain");
	case HarborName::Puerto_Santo:
		return String("Puerto Santo");
	case HarborName::Margarita:
		return String("Margarita");
	case HarborName::Caracas:
		return String("Caracas");
	case HarborName::Puerto_Cabello:
		return String("Puerto Cabello");
	case HarborName::Curacao:
		return String("Curacao");
	case HarborName::Coro:
		return String("Coro");
	case HarborName::Gibraltar:
		return String("Gibraltar");
	case HarborName::Maracaibo:
		return String("Maracaibo");
	case HarborName::Santa_Marta:
		return String("Santa Marta");
	case HarborName::Cartagena:
		return String("Cartagena");
	case HarborName::Providence:
		return String("Providence");
	}
	return String("");
}

HarborName getHarborName(String& s)
{
	auto types = Dictionary<String, HarborName>();

	types.add(String("Roatan"), HarborName::Roatan);
	types.add(String("Belize"), HarborName::Belize);
	types.add(String("Cayman"), HarborName::Cayman);
	types.add(String("Evangelista"), HarborName::Evangelista);
	types.add(String("Trinidad"), HarborName::Trinidad);
	types.add(String("Port Royale"), HarborName::Port_Royale);
	types.add(String("Santiago"), HarborName::Santiago);
	types.add(String("Port-au-prince"), HarborName::Port_au_prince);
	types.add(String("Santo Domingo"), HarborName::Santo_Domingo);
	types.add(String("Saint Kitts"), HarborName::Saint_Kitts);
	types.add(String("Santa Lucia"), HarborName::Santa_Lucia);
	types.add(String("Grenada"), HarborName::Grenada);
	types.add(String("Port of Spain"), HarborName::Port_of_Spain);
	types.add(String("Puerto Santo"), HarborName::Puerto_Santo);
	types.add(String("Margarita"), HarborName::Margarita);
	types.add(String("Caracas"), HarborName::Caracas);
	types.add(String("Puerto Cabello"), HarborName::Puerto_Cabello);
	types.add(String("Curacao"), HarborName::Curacao);
	types.add(String("Coro"), HarborName::Coro);
	types.add(String("Gibraltar"), HarborName::Gibraltar);
	types.add(String("Maracaibo"), HarborName::Maracaibo);
	types.add(String("Santa Marta"), HarborName::Santa_Marta);
	types.add(String("Cartagena"), HarborName::Cartagena);
	types.add(String("Providence"), HarborName::Providence);

	return types.get(s);
}
