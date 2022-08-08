#include <iostream>

int main()
{
	char* buffer = new char[8]; //returns a pointer to the beginning of an array of char (size 8)
	memset(buffer, 0, 8); //fills a given array with a given value for a given number of memory spaces

	char** ptrToPtr = &buffer; // pointer to pointer
	//ptrToPtr points at the address where buffer is stored.

	int a = 8;
	int& ref = a; //This creates an alias of a. This is not a new variable.
	// references are similar to const pointers they can only reference to the first variable they were referenced to.
	std::cout << a << std::endl;
	
	ref = 6;
	std::cout << a << std::endl;

	delete[] buffer;
	return 0;
}

void IncrementWithPtr(int* value)
{
	// this will take an &value as argument when called
	(*value)++;
}

void IncrementWithRef(int& value)
{
	// this will take an int value as argument when called
	value++;
}