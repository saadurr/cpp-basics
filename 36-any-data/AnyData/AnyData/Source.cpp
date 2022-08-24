#include <iostream>
#include <any>

// Available in C++ 17 and later
// not recommended to be used

int main()
{
	std::any data;
	data = 2;
	data = "Saad";
	data = std::string("Saad");

	std::string str = std::any_cast<std::string>(data);
	std::string& str1 = std::any_cast<std::string&>(data);

	std::cin.get();
	return 0;
}