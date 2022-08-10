#include <iostream>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		: m_Name(name), m_Age(-1) {}

	//explicit

	Entity(int age)
		: m_Name("RandomName"), m_Age(age) {}
};

void DummyFunction(const Entity& e)
{

}

int main()
{
	//C++ can implicitly convert the data type to the object.
	//explicit keyword must be written next to the constructor where implicit conversion is not allowed

	Entity e1 = 22; // creates an Entity e1 with age 22 and name as RandomName
	Entity e2 = std::string("Saad"); // creates an Entity e1 with name Saad and -1 age.

	DummyFunction(22); // passes an entity object with 22 age and name as RandomName.


	std::cin.get();
	return 0;
}