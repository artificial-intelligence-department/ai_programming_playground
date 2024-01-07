#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// функція для вставки значень в дерево
TreeNode *insert(TreeNode *root, int value)
{
	if (root == nullptr)
	{
		return new TreeNode(value);
	}

	if (value < root->data)
	{
		root->left = insert(root->left, value);
	}
	else
	{
		root->right = insert(root->right, value);
	}

	return root;
}

void in_order_traversal(TreeNode *root)
{
	if (root != nullptr)
	{
		in_order_traversal(root->left);
		cout << root->data << " ";
		in_order_traversal(root->right);
	}
}

void tree_sum(TreeNode *root)
{
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
	{
		return;
	}

	tree_sum(root->left);
	tree_sum(root->right);

	root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}

int main()
{
	vector<int> values = {5, 3, 7, 2, 4, 6, 8};
	TreeNode *root = nullptr;

	for (int value : values)
	{
		root = insert(root, value);
	}

	cout << "Original Tree : ";
	in_order_traversal(root);
	cout << endl;

	tree_sum(root);

	cout << "Tree After Sum Calculation : ";
	in_order_traversal(root);
	cout << endl;

	return 0;
}
