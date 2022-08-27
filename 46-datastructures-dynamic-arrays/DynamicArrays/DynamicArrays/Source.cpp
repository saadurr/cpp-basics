#include <iostream>
#include "Vector.h"

template<typename T>
void PrintVector(const Vector<T>& vector)
{
	for (int i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;

	std::cout << "-----------------------" << std::endl;
}


struct Vector3
{
	float x = 0.0f, y = 0.0f, z = 0.0f;
	Vector3(){}
	Vector3(float scalar) : x(scalar), y(scalar), z(scalar) {}
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	Vector3(const Vector3& other) :x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copied Vector3 object." << std::endl;
	}

	Vector3(Vector3&& other) noexcept : x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Moved Vector3 object." << std::endl;
	}

	~Vector3()
	{
		std::cout << "Destroyed Vector3 object." << std::endl;
	}

	Vector3& operator=(const Vector3& other)
	{
		std::cout << "Copied Vector3 object by assignment vector." << std::endl;
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	Vector3& operator=(Vector3&& other) noexcept
	{
		std::cout << "Moved Vector3 object by assignment vector." << std::endl;

		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

};

template<>
void PrintVector(const Vector<Vector3>& vector)
{
	for (int i = 0; i < vector.Size(); i++)
		std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;

	std::cout << "-----------------------" << std::endl;
}

int main()
{
#if 0
	Vector<std::string> list;
	list.PushBack("Saad");
	list.PushBack("Islamabad");
	list.PushBack("AnotherString");
	
	PrintVector(list);
#endif

	Vector<Vector3> list;
#if 0
	list.PushBack(Vector3(1.0f));
	list.PushBack(Vector3(2,3,4));
	list.PushBack(Vector3());
#endif

	list.EmplaceBack(Vector3(1.0f));
	list.EmplaceBack(Vector3(2, 3, 4));
	list.EmplaceBack(Vector3());
	list.EmplaceBack(Vector3(2.0f));
	list.EmplaceBack(Vector3(1, 4, 8));
	list.EmplaceBack(Vector3(2.0f,3.0f,4.5f));
	list.EmplaceBack(Vector3(1.0f));
	list.EmplaceBack(Vector3(21, 32, 43));
	list.EmplaceBack(Vector3());
	PrintVector(list);

	list.PopBack();
	list.PopBack();
	PrintVector(list);

	list.Clear();
	PrintVector(list);

	std::cin.get();
	return 0;
}