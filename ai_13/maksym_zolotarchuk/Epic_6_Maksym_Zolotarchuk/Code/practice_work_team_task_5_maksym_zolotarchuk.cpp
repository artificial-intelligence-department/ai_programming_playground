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

// Function to insert values into the tree
TreeNode *insertNode(TreeNode *root, int value)
{
	if (root == nullptr)
	{
		return new TreeNode(value);
	}

	if (value < root->data)
	{
		root->left = insertNode(root->left, value);
	}
	else
	{
		root->right = insertNode(root->right, value);
	}

	return root;
}

// Function for in-order traversal of the tree
void inOrderTraversal(TreeNode *root)
{
	if (root != nullptr)
	{
		inOrderTraversal(root->left);
		cout << root->data << " ";
		inOrderTraversal(root->right);
	}
}

// Function to calculate and set the sum of values in the tree
void calculateTreeSum(TreeNode *root)
{
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
	{
		return;
	}

	calculateTreeSum(root->left);
	calculateTreeSum(root->right);

	root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}

int main()
{
	vector<int> values = {5, 3, 7, 2, 4, 6, 8};
	TreeNode *root = nullptr;

	// Inserting values into the tree
	for (int value : values)
	{
		root = insertNode(root, value);
	}

	cout << "Original Tree: ";
	inOrderTraversal(root);
	cout << endl;

	// Calculating and setting the sum of values in the tree
	calculateTreeSum(root);

	cout << "Tree After Sum Calculation: ";
	inOrderTraversal(root);
	cout << endl;

	return 0;
}