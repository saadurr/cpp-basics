#include <iostream>

class Base
{
public:
	Base() {}
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	Derived() {}
	~Derived() {}
};

class AnotherClass : public Base
{
	AnotherClass() {}
	~AnotherClass() {}
};

int main()
{
	double value = 5.25;
	double a = (int)value + 5.3; //C-style casting
	std::cout << a << std::endl;

	//C++ style casting
	double s = static_cast<int>(value) + 5.3;
	std::cout << s << std::endl;


	Derived* derived = new Derived();
	Base* base = derived;

	AnotherClass* ac = dynamic_cast<AnotherClass*>(base);

	std::cin.get();
	return 0;
}