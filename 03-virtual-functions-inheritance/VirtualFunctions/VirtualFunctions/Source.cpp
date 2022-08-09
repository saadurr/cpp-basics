#include <iostream>
#include <string>


class Entity
{
public:
	std::string GetName()
	{
		return "Entity";
	}
};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name) : m_Name(name) {} //const string& is called read only reference.

	std::string GetName()
	{
		return m_Name;
	}
};

void PrintName(Entity* e)
{
	std::cout << e->GetName() << std::endl;
}

class EntityWithVirtual
{
public:
	virtual std::string GetName()
	{
		return "Entity";
	}
};

class PlayerWithVirtual : public EntityWithVirtual
{
private:
	std::string m_Name;
public:
	PlayerWithVirtual(const std::string& name) : m_Name(name) {} //const string& is called read only reference.

	std::string GetName() override //The override keyword is added in C++ 11, the program will compile even without it but it helps to improve readability.
	{
		return m_Name;
	}
};

void PrintName(EntityWithVirtual* e)
{
	std::cout << e->GetName() << std::endl;
}

int main()
{
	//std::cout << "Hello World" << std::endl;
	
	Entity* e = new Entity();
	std::cout << e->GetName() << std::endl;

	Player* p = new Player("Saad");
	std::cout << p->GetName() << std::endl;

	//The above will work fine until we start using polymorphism.

	//In the following example, the program will not function as we expect.
	Entity* entity = p;
	std::cout << entity->GetName() << std::endl;

	//Both of these will call the parent class function.
	PrintName(e);
	PrintName(p);


	std::cout << "\n\n\t::Using Virtual Functions::" << std::endl;

	EntityWithVirtual* ev = new EntityWithVirtual();
	std::cout << ev->GetName() << std::endl;

	PlayerWithVirtual* pv = new PlayerWithVirtual("Saad");
	std::cout << pv->GetName() << std::endl;

	PrintName(ev);
	PrintName(pv);

	return 0;
}