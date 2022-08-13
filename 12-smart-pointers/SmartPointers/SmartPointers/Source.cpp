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
			sharedEntity = sharedEntity2; // the pointer will only die when all of its references have died.
		}

		// Weak pointers are used when we do not want the ownership of a pointer.
		std::weak_ptr<Entity> weakEntity; // assigning a shared pointer to a weak pointer does not increase the ref count.
		{
			std::shared_ptr<Entity> sharedEntity2 = std::make_shared<Entity>();
			weakEntity = sharedEntity2; // this will die once outside this block because the weak pointer will not keep it alive.
		}
	}

	std::cin.get();
	return 0;
}