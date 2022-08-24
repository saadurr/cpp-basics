#include <iostream>
#include <fstream>
#include <tuple>
#include<optional>

//Optional is available in C++ 17 and later versions

std::string ReadFileAsString(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		// read file
		stream.close();
		return result;
	}
	return std::string(); //this function has to return something
}

std::optional<std::string> ReadFileAsString1(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		// read file
		stream.close();
		return result;
	}
	return {};
}


int main()
{
	std::string data = ReadFileAsString("data.txt");
	if (data != "")
	{
		//this checks if the file has opened successfully
		//another way could be using a bool type for success
	}


	std::optional<std::string> data1 = ReadFileAsString1("data.txt");

	//a default value can be provided as well.
	std::string value = data1.value_or("No Data");


	if (data1.has_value()) //more readable
	{
		std::cout << "File read successfully..!" << std::endl;
	}
	else
	{
		std::cout << "File failed to open..!" << std::endl;
	}

	std::cin.get();
	return 0;
}