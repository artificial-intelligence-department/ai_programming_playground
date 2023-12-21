#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

using NodePtr = Node *;

NodePtr createList()
{
	return nullptr;
}

void insert(NodePtr &head, int data)
{
	NodePtr tempPtr = new Node;
	tempPtr->data = data;
	tempPtr->next = head;
	head = tempPtr;
}

NodePtr reverse(NodePtr head)
{
	NodePtr current = head;
	NodePtr prev = nullptr;
	NodePtr next = nullptr;

	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return prev;
}

void printList(NodePtr head)
{
	if (head == nullptr)
	{
		cout << "List is empty";
	}
	else
	{
		for (NodePtr current = head; current != nullptr; current = current->next)
		{
			cout << current->data << " ";
		}
	}

	cout << endl;
}

int main()
{
	NodePtr myList = createList();
	insert(myList, 8);
	insert(myList, 3);
	insert(myList, 5);

	cout << "Original List: ";
	printList(myList);

	NodePtr reversedList = reverse(myList);

	cout << "Reversed List: ";
	printList(reversedList);

	return 0;
}
