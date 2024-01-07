#include <iostream>
#include <map>

using namespace std;

struct Node
{ // опис структури для вузлів бінарного дерева
	int value;
	Node *leftChild;
	Node *rightChild;

	Node(int val)
	{ // конструктор для вузла
		this->value = val;
		leftChild = nullptr;
		rightChild = nullptr;
	}
};

class Tree
{ // клас для бінарного дерева
private:
	Node *root;
	int treeSize;

	Node *addNode(Node *node, int val)
	{ // функція для додавання вузла до дерева
		if (node == nullptr)
		{
			treeSize++;
			return new Node(val);
		}

		if (val < node->value) // якщо значення менше за теперішнє, додавання вузла в ліве піддерево
		{
			node->leftChild = addNode(node->leftChild, val);
		}
		else if (val > node->value)
		{
			node->rightChild = addNode(node->rightChild, val);
		}

		return node; // повернення вузла
	}

	bool findNode(Node *node, int val) const // функція для пошуку значення в дереві
	{
		if (node == nullptr)
		{
			return false; // значення в дереві відсутнє
		}

		if (val == node->value)
		{
			return true;
		}
		else if (val < node->value)
		{
			return findNode(node->leftChild, val);
		}
		else
		{
			return findNode(node->rightChild, val);
		}
	}

	int calculateSize(Node *node) const // функція для обчислення розміру дерева
	{
		if (node == nullptr)
		{
			return 0;
		}

		return 1 + calculateSize(node->leftChild) + calculateSize(node->rightChild); // розмір дерева дорівнює 1 плюс розмір лівого та правого піддерев
	}

	void printTree(Node *node) const // функція для друку дерева в порядку зростання
	{
		if (node != nullptr)
		{
			printTree(node->leftChild);
			cout << node->value << " ";
			printTree(node->rightChild);
		}
	}

public:
	Tree() : root(nullptr), treeSize(0) {} // конструктор для дерева

	void insert(int val)
	{
		root = addNode(root, val); // додаємо вузол з заданим значенням в дерево
	}

	bool contains(int val) const
	{
		return findNode(root, val);
	}

	int size() const
	{
		return calculateSize(root); // обчислення розміру дерева
	}

	friend ostream &operator<<(ostream &os, Tree &bst) // перевантажую оператор << для друку дерева
	{
		bst.printTree(bst.root); // друкую дерево
		return os;
	}
};

int main()
{
	int Q; // кількість операцій
	cin >> Q;

	Tree bst;						  // створення бінарного дерева
	map<string, int> commandMap; // cтворення map для команд
	commandMap["insert"] = 1;	  // відображення операцій на 1;2;3;4
	commandMap["contains"] = 2;
	commandMap["size"] = 3;
	commandMap["print"] = 4;

	while (Q--)
	{
		string operation;
		cin >> operation;

		switch (commandMap[operation])
		{		  //
		case 1: // якщо operation дорівнює “insert”, зчитується значення і вставляється в bst
		{
			int value;
			cin >> value;
			bst.insert(value);
			break;
		}
		case 2: // якщо operation дорівнює “contains”, зчитується значення і перевіряється, чи містить bst це значення
		{
			int value;
			cin >> value;
			cout << (bst.contains(value) ? "Yes" : "No") << endl;
			break;
		}
		case 3: // якщо operation дорівнює “size”, виводиться розмір bst
		{
			cout << bst.size() << endl;
			break;
		}
		case 4: // якщо operation дорівнює “print”, виводиться bst(бінарне дерево)
		{
			cout << bst << endl;
			break;
		}
		default: // в іншому випадку виводиться помилка
			cout << "Invalid command" << endl;
		}
	}

	return 0;
}