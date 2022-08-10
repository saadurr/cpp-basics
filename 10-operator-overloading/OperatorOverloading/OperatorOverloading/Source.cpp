#include <iostream>

struct Vector2
{
	float x, y;
	
	Vector2(float x, float y)
		:x(x), y(y) {}

	Vector2 operator+ (const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator* (const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	bool operator== (const Vector2& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other)
	{
		return !(*this == other);
	}

	friend std::ostream& operator<< (std::ostream& stream, const Vector2& other)
	{
		stream << other.x << ", " << other.y;
		return stream;
	}
};

int main()
{
	Vector2 speed(2.5f, 1.8f);
	Vector2 position(3.8f, 10.0f);
	Vector2 powerUp(1.1f, 1.1f);

	Vector2 result = speed + position * powerUp;

	std::cout << result << std::endl;

	std::cin.get();
	return 0;
}