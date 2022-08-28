#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int> values;
	values.EmplaceBack(1);
	values.EmplaceBack(2);
	values.EmplaceBack(3);
	values.EmplaceBack(4);
	values.EmplaceBack(5);

	//iterating using for-loop
	std::cout << "Iterating using for-loop:" << std::endl;
	for (int i = 0; i < values.Size(); i++)
		std::cout << values[i] << std::endl;

	//iterating using for-range loop
	std::cout << "---------------\n\n";
	std::cout << "Iterating using for-range loop:" << std::endl;
	for (int value : values)
		std::cout << value << std::endl;

	//iterating using a for-loop using iterator
	std::cout << "---------------\n\n";
	std::cout << "Iterating using a for-loop using iterator:" << std::endl;
	for (Vector<int>::Iterator it = values.begin(); it != values.end(); ++it)
		std::cout << *it << std::endl;



	std::cin.get();
	return 0;
}