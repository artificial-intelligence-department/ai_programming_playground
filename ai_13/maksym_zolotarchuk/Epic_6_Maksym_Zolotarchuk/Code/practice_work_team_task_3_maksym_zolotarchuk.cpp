#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;

	explicit Node(int val) : data(val), next(nullptr) {}
};

Node *createNode(int data)
{
	return new Node(data);
}

void push(Node *&head, int data)
{
	Node *newNode = createNode(data);
	newNode->next = head;
	head = newNode;
}

Node *addTwoLists(const Node *first, const Node *second)
{
	Node *result = nullptr;
	Node *temp = nullptr;
	Node *previous = nullptr;
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

void printList(const Node *node)
{
	while (node != nullptr)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << std::endl;
}

void deleteList(Node *&head)
{
	while (head != nullptr)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
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

	// Очистка пам'яті після використання списків
	deleteList(firstList);
	deleteList(secondList);
	deleteList(resultList);

	return 0;
}
