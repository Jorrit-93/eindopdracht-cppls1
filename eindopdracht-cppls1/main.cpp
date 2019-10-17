#include <iostream>
#include "random.h"
#include "turn_view.h"
#include "in_battle_view.h"
#include "on_sea_view.h"
#include "in_harbor_view.h"

int main()
{
	auto option1 = new String("option1");
	auto option2 = new String("option2");
	auto option3 = new String("option3");
	auto options = new Array<String*>(3);
	options->add(option1);
	options->add(option2);
	options->add(option3);


	auto key1 = new String("hp");
	auto key2 = new String("gold");
	auto key3 = new String("stock");
	auto value1 = new String("10000");
	auto value2 = new String("1000");
	auto value3 = new String("350");
	auto dictionary = new Dictionary<String*, String*>();
	dictionary->add(key1, value1);
	dictionary->add(key2, value2);
	dictionary->add(key3, value3);
	
	auto test = InBattleView();
	test.printGeneralOutput(dictionary);
	
	auto choice = test.getInput(options);

	std::cout << "you choose: " << *choice << "\n";
	std::cout << Random::global()->randomInt(0, 100) << "\n";
}
