#include <iostream>

// lvalues are those values that occupy a space in memory and have a location
// rvalues are those values that do not occupy a space by default. These are temporaries.

int GetValue()
{
	return 10;
}

int SetValue(int val) //rvalues cannot be passed as reference - changing the argument type to reference type can be used to test rvalue
{
	return val;
}

#if 0
int SetValue(const int& val) //This function can accept both rvalues and lvalues as argument
{

}
#endif

void PrintString(std::string& str) //only accepts lvalues
{
	std::cout << str << std::endl;
}

void PrintStringLR(const std::string& str) //accepts both lvalue and rvalue
{

}

void PrintStringRvalue(std::string&& str) //accepts only rvalue
{

}

int main()
{
	int i = GetValue(); //left side of the expression is lvalue and right side of the expression is rvalue.

	SetValue(i); //calling SetValue with an lvalue
	SetValue(10); //calling SetValue with an rvalue


	std::string firstName = "Saad Ur";
	std::string lastName = "Rehman";
	std::string fullName = firstName + lastName; //the left side of expression is lvalue and right side is rvalue because it gets discarded and is not stored anywhere
	
	//PrintString can be called for fullName but not for firstName+lastName


	std::cin.get();
	return 0;
}