#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode *lChild;
	TreeNode *rChild;

	TreeNode(int val)
	{
		this->data = val;
		lChild = nullptr;
		rChild = nullptr;
	}
};

class Tree
{
private:
	TreeNode *root;
	int treeSize;

	TreeNode *aNode(TreeNode *node, int val)
	{
		if (node == nullptr)
		{
			treeSize++;
			return new TreeNode(val);
		}

		if (val < node->data)
		{
			node->lChild = aNode(node->lChild, val);
		}
		else if (val > node->data)
		{
			node->rChild = aNode(node->rChild, val);
		}

		return node;
	}

	bool fNode(TreeNode *node, int val) const
	{
		if (node == nullptr)
		{
			return false;
		}

		if (val == node->data)
		{
			return true;
		}
		else if (val < node->data)
		{
			return fNode(node->lChild, val);
		}
		else
		{
			return fNode(node->rChild, val);
		}
	}

	int calcSize(TreeNode *node) const
	{
		if (node == nullptr)
		{
			return 0;
		}

		return 1 + calcSize(node->lChild) + calcSize(node->rChild);
	}

	void printTree(TreeNode *node) const
	{
		if (node != nullptr)
		{
			printTree(node->lChild);
			cout << node->data << " ";
			printTree(node->rChild);
		}
	}

public:
	Tree() : root(nullptr), treeSize(0) {}

	void insert(int val)
	{
		root = aNode(root, val);
	}

	bool contains(int val) const
	{
		return fNode(root, val);
	}

	int size() const
	{
		return calcSize(root);
	}

	friend ostream &operator<<(ostream &os, Tree &bst)
	{
		bst.printTree(bst.root);
		return os;
	}
};

int main()
{
	int Q;
	cin >> Q;

	Tree bst;

	while (Q--)
	{
		string operation;
		cin >> operation;

		if (operation == "insert")
		{
			int value;
			cin >> value;
			bst.insert(value);
		}
		else if (operation == "contains")
		{
			int value;
			cin >> value;
			if (bst.contains(value))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else if (operation == "size")
		{
			cout << bst.size() << endl;
		}
		else if (operation == "print")
		{
			cout << bst << endl;
		}
	}

	return 0;
}