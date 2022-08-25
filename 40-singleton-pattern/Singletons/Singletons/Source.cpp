#include <iostream>

// Singletons in C++ is a way of organizing global variables and functions.
// They can be thought similar to namespaces

class Singleton
{
private:
	Singleton() {}  //constructor is private so that not everyone can instantiate this class

	static Singleton s_Instance;

public:
	static Singleton& Get()
	{
		return s_Instance;
	}

	void TestFunction()
	{

	}

	Singleton(const Singleton&) = delete; // deleting the copy constructors so that no copies can be created
};

Singleton Singleton::s_Instance;

// Implementing a real class with the same design pattern

class RandomGenerator
{
private:
	RandomGenerator() {}  //constructor is private so that not everyone can instantiate this class

	static RandomGenerator s_Instance;

	float randomNumber = 0.5f;

public:
	static RandomGenerator& Get()
	{
		return s_Instance;
	}

	float Generate()
	{
		return randomNumber;
	}

	RandomGenerator(const RandomGenerator&) = delete; // deleting the copy constructors so that no copies can be created
};
RandomGenerator RandomGenerator::s_Instance;

// A modified singleton pattern
class RandomGenerator2
{
private:
	RandomGenerator2() {}  //constructor is private so that not everyone can instantiate this class

	static RandomGenerator2 s_Instance;

	float randomNumber = 0.5f;

	float IGenerate() //I represents internal
	{
		return randomNumber;
	}

public:
	static RandomGenerator2& Get()
	{
		return s_Instance;
	}
	static float Generate()
	{
		return Get().IGenerate();
	}
	

	RandomGenerator2(const RandomGenerator2&) = delete; // deleting the copy constructors so that no copies can be created
};
RandomGenerator2 RandomGenerator2::s_Instance;

int main()
{
	Singleton::Get().TestFunction(); // Using the singleton instance to call that function

	float rNumber = RandomGenerator::Get().Generate();


	std::cin.get();
	return 0;
}