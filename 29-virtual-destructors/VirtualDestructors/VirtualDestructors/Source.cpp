#include <iostream>

// Virtual destructors are important when dealing with polymorphism.

class Base
{
public:
	Base()
	{
		std::cout << "Constructed Base Class." << std::endl;
	}

	virtual ~Base() //the base destructor needs to be virtual so that the program knows there are other destructors to be called down the hierarchy.
	{
		std::cout << "Destroyed Base Class." << std::endl;
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Constructed Derived Class." << std::endl;
	}

	~Derived()
	{
		std::cout << "Destroyed Derived Class." << std::endl;
	}
};

void PrintSeperator()
{
	std::cout << "\t-----------------\n";
}

int main()
{
	Base* base = new Base();
	delete base;

	PrintSeperator();

	Derived* derived = new Derived();
	delete derived;

	PrintSeperator();

	Base* poly = new Derived();
	delete poly; // destructor of derived is not called

	std::cin.get();
	return 0;
}