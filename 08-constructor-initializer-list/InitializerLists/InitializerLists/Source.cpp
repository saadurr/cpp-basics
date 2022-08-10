#include <iostream>

// Constructor Initializer List / Memory Initializer Lists are more efficient than regular constructors.
// Using ternary operator for conditions makes code look cleaner and a bit faster.

static int s_Level = 1;
static int s_Speed = 2;

void TernaryOperatorExample()
{
	s_Speed = s_Level > 5 ? 10 : 5;

	std::cout << s_Speed << std::endl;
}

class Entity
{
private:
	std::string m_Name;
public:
	// The order of the initializer list should be the same as the order in which the variables have been defined.
	Entity()
		: m_Name("Unknown")
	{}

	Entity(const std::string& name) 
		: m_Name(name) 
	{}

#if 0
	//Regular parametrized constructor
	Entity(const std::string& name)
	{
		m_Name = name;
	}
#endif
	const std::string& GetName() const
	{
		return m_Name;
	}
};


int main()
{
	Entity e("Saad");
	std::cout << e.GetName() << std::endl;

	TernaryOperatorExample();

	std::cin.get();
	return 0;
}