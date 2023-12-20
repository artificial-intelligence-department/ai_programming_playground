#include <iostream>

struct Node
{
	int data;
	Node *next;
};

Node *createNode(int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	return newNode;
}

void push(Node *&head, int data)
{
	Node *newNode = createNode(data);
	newNode->next = head;
	head = newNode;
}

Node *addTwoLists(Node *first, Node *second)
{
	Node *result = nullptr;
	Node *temp, *previous = nullptr;
	int carry = 0, sum;

	while (first != nullptr || second != nullptr)
	{
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = createNode(sum);

		if (result == nullptr)
		{
			result = temp;
		}
		else
		{
			previous->next = temp;
		}

		previous = temp;

		if (first)
		{
			first = first->next;
		}
		if (second)
		{
			second = second->next;
		}
	}

	if (carry > 0)
	{
		temp->next = createNode(carry);
	}

	return result;
}

void printList(Node *node)
{
	while (node != nullptr)
	{
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

int main()
{
	Node *firstList = nullptr;
	Node *secondList = nullptr;

	push(firstList, 9);
	push(firstList, 7);
	push(firstList, 3);

	push(secondList, 9);
	push(secondList, 7);
	push(secondList, 3);

	Node *resultList = addTwoLists(firstList, secondList);
	printList(resultList);

	return 0;
}
