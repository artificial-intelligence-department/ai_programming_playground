#include "List.h"
#include <iostream>
using namespace std;
List::List(): head(nullptr), tail(nullptr), size(0){}

List::~List()
{
	Clear();
}

void List::Clear()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}

void List::PopFront()
{
	if (size == 0)
	{
		return;
	}

	if (size == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		head->previous = nullptr;
		delete temp;
	}
	size--;
}

void List::Add(const char*& value, const int& position)
{
	int counter = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (counter == position)
		{
			Node* NextCurrent = current->next;
			current->next = new Node{ value, nullptr, nullptr };
			current = current->next;
			current->previous = current;
			current->next = NextCurrent;
			return;
		}
		counter++;
		current = current->next;
	}
}

int List::Size()
{
	return size;
}

void List::PushBack(const char*& value)
{
	if (size == 0)
	{
		head = new Node{ value, nullptr, nullptr };
		tail = head;
	}
	else
	{
		tail->next = new Node{ value, nullptr, nullptr };
		tail = tail->next;
	}
	size++;
}

int List::SearchFirstSymbol(const char& symbol)
{
	int counter = 0;
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data[0] == symbol)
		{
			return counter;
		}
		counter++;
		current = current->next;
	}
	return -1;
}

void List::Show() const
{
	if (size == 0)
	{
		cout <<"List is empty\n";
		return;
	}

	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
