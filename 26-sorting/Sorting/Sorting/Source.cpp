#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> values = { 1,5,7,8,921,25,56,48,9,76 };
	
	std::sort(values.begin(), values.end()); // sort ascending
	for (const int& v : values)
		std::cout << v << std::endl;

	std::sort(values.begin(), values.end(), std::greater<int>()); // sort descending
	for (const int& v : values)
		std::cout << v << std::endl;


	std::cin.get();
	return 0;
}