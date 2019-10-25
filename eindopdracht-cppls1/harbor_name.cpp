#include "harbor_name.h"
#include "dictionary.h"

std::ostream& operator<<(std::ostream& os, const HarborName harbor_name)
{
	const auto string = harborNameToString(harbor_name);
	os << string;
	delete string;
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
