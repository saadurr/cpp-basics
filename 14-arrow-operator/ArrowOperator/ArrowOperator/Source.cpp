#include <iostream>

class Entity
{
public:
	int x;
public:
	void Print() const
	{
		std::cout << "Entity's Print Function" << std::endl;
	}
};

//Arrow operator can be overloaded just like other operators

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity)
	{
	}
	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->()
	{
		return m_Obj;
	}
};

//Using the arrow operator, the offset of struct members in memory can be calculated
struct Vector3
{
	float x, y, z;
};

int main()
{
	Entity e;
	e.Print();

	Entity* ep;
	ep = &e;

	ep->Print(); //equivalent of (*ep).Print()

	ScopedPtr ptr = new Entity();
	ptr->Print();

	int offset = (int)& ((Vector3*)nullptr)->x;
	std::cout << offset << std::endl;

	offset = (int)&((Vector3*)nullptr)->y;
	std::cout << offset << std::endl;

	offset = (int)&((Vector3*)nullptr)->z;
	std::cout << offset << std::endl;

	std::cin.get();
	return 0;
}