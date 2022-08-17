#include <iostream>

// Unions allow to have multiple names for addressing the same data.

struct Vector2 
{
	float x, y;
};

struct Vector4
{
	union
	{
		struct 
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b; //vector a corresponds to x & y, while vector b corresponds to z & w.
		};
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	Vector4 vector = { 1.0f, 2.0f, 3.0f,4.0f };
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cout << " ---------------------- " << std::endl;

	vector.z = 500.0f;
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cin.get();
	return 0;
}