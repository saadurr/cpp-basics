#include <iostream>

class Entity
{
public:
	int x, y;

	Entity(int x, int y);
};

void PrintEntity(Entity* e);
void PrintEntity(const Entity& e);

Entity::Entity(int x, int y)
{
	this->x = x;
	this->y = y;

	PrintEntity(this);
	PrintEntity(*this);
}

void PrintEntity(Entity* e)
{
	std::cout << e->x << ", " << e->y << std::endl;
}


void PrintEntity(const Entity& e)
{
	std::cout << e.x << ", " << e.y << std::endl;
}




int main()
{

	std::cin.get();
	return 0;
}