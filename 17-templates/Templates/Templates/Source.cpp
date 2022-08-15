#include <iostream>

// A template is basically asking the compiler write code when required (when a template is used).
// A template is not compiled unless it is used.

template <typename T>
void PrintValue(T value)
{
	std::cout << value << std::endl;
}

template <typename T, int n>
class Array
{
private:
	T array[n];
public:
	int GetSize() const
	{
		return n;
	}
};	

int main()
{
	//implicit casting is happening here
	PrintValue(5);
	PrintValue(6.01f);
	PrintValue("Saad");
	PrintValue('S');

	//explicitly defining type
	PrintValue<int>(5);
	PrintValue<float>(6.01f);
	PrintValue<std::string>("Saad");
	PrintValue<char>('S');

	Array<std::string, 2> StringArray;
	std::cout << StringArray.GetSize() << std::endl;


	std::cin.get();
	return 0;
}