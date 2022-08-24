#include <iostream>
#include <string>

// Stringview is a const char pointer to a memory location, along with a size.
// It allows for strings to be used without having new allocations.

static uint32_t s_AllocCount = 0;

//to track memory allocations, the new operator can be overloaded
void* operator new(size_t size)
{
	s_AllocCount++;
	std::cout << "Allocating " << size << " bytes.\n";

	return malloc(size);
}


void PrintString(const std::string& str)
{
	std::cout << str << std::endl;
}

void PrintString(std::string_view str)
{
	std::cout << str << std::endl;
}

int main()
{
	std::string name = "Saad Rehman";
#if 0
	std::string name = "Saad Rehman"; // if this is made const char* name then it will lead to zero allocations
	std::string fName = name.substr(0, 4);
	std::string lName = name.substr(5, 9);
#else
	//const char* name = "Saad Rehman";
	std::string_view fName(name.c_str(), 4);
	std::string_view lName(name.c_str() + 5, 9);
#endif
	PrintString(fName);
	PrintString(lName);


	std::cout << "\nTotal Allocations in the program: " << s_AllocCount << std::endl;
	std::cin.get();
	return 0;
}