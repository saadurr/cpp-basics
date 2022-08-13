#include <iostream>

//Copy constructors are required when dealing with memory with heap or pointers.
// Vector2* a = new Vector2();
// Vector2* b = a;
// Now both a and b point at the same object

struct Vector2
{
	float x, y;

};

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	String(const String& other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& str)
{
	std::cout << str << std::endl;
}

int main()
{
	String str = "Saad";
	String str2 = str;
	PrintString(str);
	PrintString(str2);
	//std::cout << str << std::endl;
	//std::cout << str2 << std::endl;

	str2[2] = 'b';
	PrintString(str);
	PrintString(str2);
	//std::cout << str << std::endl;
	//std::cout << str2 << std::endl;

	std::cin.get();
	return 0;
}