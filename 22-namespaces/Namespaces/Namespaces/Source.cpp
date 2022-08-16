#include <iostream>

// Namespaces allow same symbols to be used in different contexts in the same program
// C does not have namespaces.

namespace Nest 
{
	namespace FirstLevel
	{
		void function()
		{
			std::cout << "Function inside FirstLevel namespace inside Nest namespace." << std::endl;
		}
	}

	void function()
	{
		std::cout << "Function inside Nest namespace." << std::endl;
	}

}

namespace Test
{
	void Function()
	{
		std::cout << "Function inside Test namespace." << std::endl;
	}
}

int main()
{
	Nest::function();
	Nest::FirstLevel::function();

	namespace NFL = Nest::FirstLevel;
	NFL::function();

	Test::Function();

	std::cin.get();
	return 0;
}