#include <iostream>

int main()
{
	int* array = new int[50]; //pointer to array

	int** a2d = new int*[50]; //pointer to array of pointers
	for (int i = 0; i < 50; i++)
		a2d[i] = new int[50];
	
	for (int i = 0; i < 50; i++)
		delete[] a2d[i];
	delete[] a2d; 
	//array of arrays can result in memory fragmentation


	int*** a3d = new int** [50]; //pointer to array of array of pointers
	for (int i = 0; i < 50; i++)
	{
		a3d[i] = new int*[50];

		for (int j = 0; j < 50; j++)
		{
			int** ptr = a3d[i];
			ptr[j] = new int[50];
		}
	}


	std::cin.get();
	return 0;
}