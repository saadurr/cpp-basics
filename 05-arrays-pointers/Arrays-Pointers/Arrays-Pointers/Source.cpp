#include <iostream>
#include <array>

int main()
{
	int arr[5];
	int* ptr = arr; //Now ptr points to arr
	
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i + 1;
	}

	//Using pointers to dereference
	std::cout << "The member on 3rd entry is " << *(ptr + 2) << std::endl;

	//The memory block depends on the type of pointer variable.
	std::cout << "The member on 2nd entry is " << *(int*)((char*)ptr + 4) << std::endl;


	// Creating arrays on heap memory
	int* heapArr = new int[5];
	delete[] heapArr;

	// For C++ 11 and higher versions:
	std::array<int, 5> newArr;
	for (int i = 0; i < newArr.size(); i++)
		newArr[i] = 0;

	return 0;
}