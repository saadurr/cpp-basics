#include <iostream>
#include <string>


/*
* Pure Virtual Functions are the equivalent of abstract method or interfaces in Java / C#.
* These functions do not have implementations in base class but force the sub-classes to implement.
* 
* A class is made abstract by declaring at least one of its functions as pure virtual function. 
* A pure virtual function is specified by placing "= 0"
*/

class Printable
{
public:
	virtual std::string GetClassName() = 0; //Pure Virtual Function
};

class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity";} //Pure Virtual Function
	std::string GetClassName() override
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

	std::string GetName() override
	{
		return m_Name;
	}
	std::string GetClassName() override
	{
		return "Player";
	}
};


void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{

	Entity* e = new Entity();
	Player* p = new Player("Saad");

	Print(e);
	Print(p);
	
	return 0;
}