#include <iostream>

// Type punning is often used in C++ for fast floating - point math, deserialising C++ objects from a sequence of bytes, and other purposes.

// A form of pointer aliasing where two pointers and refer to the same location in memory but represent that location as different types. 
// The compiler will treat both "puns" as unrelated pointers. 
// Type punning has the potential to cause dependency problems for any data accessed through both pointers.

struct Entity
{
	int x, y;
};

int main()
{
	int a = 50;
	double value = *(double*) & a; //casting an int into a double pointer and then dereferencing
	// this is reading memory that was not supposed to be read. It is trying to read 8 bytes of memory where the int was stored in 4 bytes only.

	std::cout << value << std::endl;


	Entity e = { 5,8 };

	int* position = (int*) &e;

	int y = *(int*)((char*)&e + 4);

	std::cout << position[0] << ", " << position[1] << std::endl;
	std::cout << y;

	std::cin.get();
	return 0;
}