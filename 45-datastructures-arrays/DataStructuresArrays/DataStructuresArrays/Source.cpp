#include <iostream>

template <typename T, size_t S>
class Array
{
private:
	T m_Data[S];
public:
	Array()
	{}

	constexpr int Size() const //can be evalueated at compile time due to constexpr
	{
		return S;
	}

	T& operator[](size_t index)
	{
		return m_Data[index];
	}
	const T& operator[] (size_t index) const //to handle an Array instance that is const
	{
		return m_Data[index];
	}
};

int main()
{
	Array<int, 5> data;

	static_assert(data.Size() < 10, "Size is too large!");

	//Array<std::string, data.Size()> newArray; //example

	memset(&data[0], 0, data.Size()*sizeof(int));

	for (int i = 0; i < data.Size(); i++)
		std::cout << data[i] << std::endl;

	std::cin.get();
	return 0;
}