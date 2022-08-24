#include <iostream>
#include <variant>

// std::variant allows for storing multiple data types in a single variable
// available in C++ 17 and later



int main()
{
	std::variant < std::string, int> data;
	data = "Saad";
	std::cout << std::get<std::string>(data) << std::endl;

	data = 2;
	std::cout << std::get<int>(data) << std::endl;

	//If data is accessed as string here, it will raise a variant access error
	//to check the type, data.index() can be used to get the index of the types or get_if can be used
	if (auto value = std::get_if<std::string>(&data))
	{
		//type is string
		std::string& v = *value;
	}

	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(std::string) << std::endl;
	std::cout << sizeof(data) << std::endl;

	std::cin.get();
	return 0;
}