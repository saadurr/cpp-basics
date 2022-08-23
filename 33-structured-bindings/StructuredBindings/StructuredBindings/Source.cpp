#include <iostream>
#include <string>
#include <tuple>

// Structured Bindings have been introduced in C++ 17 and they allow a way of having more than one return types and variables.

std::tuple<std::string, int> CreatePerson()
{
	return { "Saad", 23 };
}

int main()
{

	//Tuples are one way of handling multiple return types but accessing tuple members is a bit difficult.
	std::tuple<std::string, int> person = CreatePerson();
	std::string& name = std::get<0>(person);
	int age = std::get<1>(person);

	//The tie method can be used as well for this purpose
	std::string strName;
	int age2;
	std::tie(strName, age2) = CreatePerson();

	//Another solution to this would be using structures.

	//In C++ 17 and later, structured bindings are available which provide an easier way of handling more than one and different return types.
	auto [aName, aAge] = CreatePerson();
	std::cout << aName << " " << aAge << std::endl;

	std::cin.get();
	return 0;
}