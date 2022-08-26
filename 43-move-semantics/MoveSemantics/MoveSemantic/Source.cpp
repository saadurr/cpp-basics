#include <iostream>

class String
{
private:
	char* m_Data;
	uint32_t m_Size;
public:
	String() = default;

	String(const char* string)
	{
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	String(const String& other)
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	String(String&& other) noexcept
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data; //assigning the pointer instead of actually copying the data (shallow copy)

		//to make sure that the rvalue doesnt get deleted after this, we make it a hollow object (empty state)
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	~String()
	{
		printf("Destroyed!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}

};

class Entity
{
private:
	String m_Name;
public:
	Entity(const String& name) //without move semantics, this entity used in the main function will be creating a String object and then recreating - so it allocates memory twice.
		:m_Name(name)
	{}

	Entity(String&& name) //rvalue reference type in argument
		:m_Name((String&&)name)
	{}

	void Print()
	{
		m_Name.Print();
	}
};

int main()
{
	Entity entity("Saad");
	entity.Print();

	std::cin.get();
	return 0;
}