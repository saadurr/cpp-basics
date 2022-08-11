#include <iostream>

struct Node
{
	int data;
	Node* next;

	Node(int value)
	{
		data = value;
		next = NULL;
	}
};

class LinkedList
{
private:
	Node* head;
public:
	LinkedList() { head = NULL; }
	void Add(int value);
	void Delete(int value);
	int SearchValue(int value);
	void Print();
};

int main()
{
	LinkedList l;
	l.Add(1);
	l.Add(2);
	l.Print();

	std::cin.get();
	return 0;
}

void LinkedList::Add(int value)
{
	if (head == NULL) // empty list
	{
		head = new Node(value);
		return;
	}

	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new Node(value);
}

void LinkedList::Print()
{
	std::cout << "Printing List" << std::endl;
	if (head == NULL) // empty list
	{
		std::cout << "/t/t**Empty List**" << std::endl;
		return;
	}

	Node* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << "END" << std::endl;
}