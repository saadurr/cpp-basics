#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	std::vector<int> values = { 1,2,3,4,5,6,7,8,9,10 };

	//iterating using for-loop
	std::cout << "Iterating using for-loop:" << std::endl;
	for (int i = 0; i < values.size(); i++)
		std::cout << values[i] << std::endl;

	//iterating using for-range loop
	std::cout << "---------------\n\n";
	std::cout << "Iterating using for-range loop:" << std::endl;
	for (int value : values)
		std::cout << value << std::endl;

	//iterating using a for-loop using iterator
	std::cout << "---------------\n\n";
	std::cout << "Iterating using a for-loop using iterator:" << std::endl;
	for (std::vector<int>::iterator it = values.begin(); it != values.end(); ++it)
		std::cout << *it << std::endl;
	

	//Using iterators with unordered map

	using scoremap = std::unordered_map<std::string, int>;

	std::unordered_map<std::string, int> map;
	map["Saad"] = 0;
	map["Text"] = 1;
	map["NewText"] = 2;

	std::cout << "---------------\n\n";
	std::cout << "Iterators in for-loop with unordered maps:" << std::endl;
	//for (std::unordered_map<std::string, int>::const_iterator it = map.begin(); it != map.end(); ++it)
	for (scoremap::const_iterator it = map.begin(); it != map.end(); ++it)
	{
		auto& key = it->first;
		auto& value = it->second;

		std::cout << key << " : " << value << std::endl;
	}
	std::cout << "---------------\n\n";
	std::cout << "Iterators in for-range with unordered maps:" << std::endl;
	for (const auto& entry : map)
		std::cout << entry.first << " : " << entry.second << std::endl;

	//using structured bindings
	std::cout << "---------------\n\n";
	std::cout << "Iterators in for-range loop with structured bindings:" << std::endl;
	for (const auto&[key, value] : map)
		std::cout << key << " : " << value << std::endl;
	

	std::cin.get();
	return 0;
}