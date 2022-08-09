#include <iostream>
#include <string>

//Always use const when passing strings to a function to avoid making copies
void PrintString(const std::string& str)
{
	std::cout << str << std::endl;
}

int main()
{
	const char* name = "Saad";
	char name2[5] = { 'S','a', 'a', 'd',0 }; // 0 is the null termination character here.

	// With char pointer arrays, we have to use strcpy and strlen
	std::cout << name << std::endl;
	std::cout << name2 << std::endl;
	
	std::string strName = "Saad Ur Rehman";
	std::string strWelcome = std::string("Hello ") + "Saad!"; // direct concatentaion is not allowed since both are const char arrays
	bool contains = strName.find("Rehman") != std::string::npos;

	const wchar_t* name4 = L"WideChar";

	// For C++ 11 and higher:
	const char16_t* name5 = u"16bitChar";
	const char32_t* name6 = U"32bitChar";

	return 0;
}