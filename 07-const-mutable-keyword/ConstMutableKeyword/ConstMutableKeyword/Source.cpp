#include <iostream>

//using const in class methods
class Entity
{
private:
	int m_X, m_Y;
	mutable int debug_count; //marked with mutable, a variable can be modified insied a const function
public:
	// marking a function const in a class will restrict it from changing any members of the class
	int GetX() const
	{
		debug_count++;
		return m_X;
	}
	void SetX(int x)
	{
		m_X = x;
	}
};

// mutables with lambda functions
void TestFunction()
{
	int x = 8;
	auto f = [=]() mutable //marking a lambda with mutable is equivalent of creating another variable inside and copying the value of x into that variable
	{
		x++; //this change will not reflect to the x outside this lambda
		std::cout << x << std::endl;
	};

	f();
}

int main()
{
	//const with integers
	const int MAX_SIZE = 1000;
	int x = 1000;
	//Changing MAX_SIZE will result into an error

	//const with pointers
	int* a = new int; // int on heap
	//without const, a pointer can be dereferenced, its addressed can be changed.
	*a = 3;
	a = (int*) &MAX_SIZE;

	//There are two types of pointers with const:
	const int* p1 = new int; // can be also written as int const* b
	p1 = &x; //address stored can be changed but dereferenced value cannot be changed.

	int* const p2 = new int; // dereferenced value can be changed but address cannot be changed
	*p2 = 4;

	std::cin.get();

	return 0;
}