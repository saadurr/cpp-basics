#include <iostream>
#include <memory> //library for smart pointers


class Entity
{
public:
	Entity()
	{
		std::cout << "Entity Created" << std::endl;
	}
	~Entity()
	{
		std::cout << "Entity Destroyed" << std::endl;
	}
};

int main()
{
	{
		std::unique_ptr<Entity> uniqueEntity = std::make_unique<Entity>(); //it is a scoped pointer and will be destroyed after its scope.
	}
	{
		std::shared_ptr<Entity> sharedEntity; // this pointer uses reference count
		{
			std::shared_ptr<Entity> sharedEntity2 = std::make_shared<Entity>();
			sharedEntity = sharedEntity2;
		}

		std::weak_ptr<Entity> weakEntity; // weak pointer
	}

	std::cin.get();
	return 0;
}