#include <iostream>
#include <string>

class Entity
{
public:
	virtual void SomeFunction()
	{

	}
};

class Player : public Entity
{

};

class Enemy : public Entity
{

};

int main()
{
	Player* player = new Player();
	Entity* e = player; // implicit casting

	// This commented statement is not possible because it needs to be casted before
	// Player* p = e;

	// The below statement can also work but it can generate issues
	Player* p = (Player*)e;

	// The better way to do this is dynamic cast but it needs the class to have at least one virtual function so that v-table is generated
	Entity* actuallyEnemy = new Enemy();
	Entity* actuallyPlayer = new Player();

	// Dynamic cast only returns a value if the cast is valid and returns null if the cast is invalid
	Player* p1 = dynamic_cast<Player*>(actuallyEnemy);
	Player* p0 = dynamic_cast<Player*>(actuallyPlayer);

	std::cin.get();
	return 0;
}