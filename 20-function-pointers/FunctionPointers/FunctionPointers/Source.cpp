#include <iostream>
#include <vector>

void RandomFunction()
{
	std::cout << "Hello from Random Function" << std::endl;
}

void RandomFunctionWithArg(int a)
{
	std::cout << "Hello from Random Function. Argument passed is " << a << std::endl;
}

void PrintValue(int v)
{
	std::cout << v << std::endl;
}

void ForEach(std::vector<int> values, void(*F)(int))
{
	for (int value : values)
		F(value);
}

int main()
{
	auto function = RandomFunction; //equivalent of &RandomFunction as it returns the address of where the instructions are stored
	function();

	void (*function2)() = RandomFunction; //this is the type of the pointer that the function returns

	auto functionArg = RandomFunctionWithArg;
	functionArg(2);

	void (*functionArg2)(int) = RandomFunctionWithArg;
	functionArg(20);


	std::vector<int> values = { 1,2,3,4,5 };
	ForEach(values, PrintValue);

	//Instead of passing the function pointer, we can also use a lambda function here

	ForEach(values, [](int v) {std::cout << v << std::endl; });


	std::cin.get();
	return 0;
}