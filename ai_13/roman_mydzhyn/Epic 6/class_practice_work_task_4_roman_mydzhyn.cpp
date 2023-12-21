#include <iostream>

struct TreeNode
{
	int value;
	TreeNode *leftChild;
	TreeNode *rightChild;

	TreeNode(int val) : value(val), leftChild(nullptr), rightChild(nullptr) {}
};

void insertNode(TreeNode *&rootNode, int val)
{
	if (rootNode == nullptr)
	{
		rootNode = new TreeNode(val);
	}
	else if (val < rootNode->value)
	{
		insertNode(rootNode->leftChild, val);
	}
	else
	{
		insertNode(rootNode->rightChild, val);
	}
}

TreeNode *create_mirror_flip(TreeNode *rootNode)
{
	if (rootNode == nullptr)
	{
		return nullptr;
	}

	TreeNode *mirrorRootNode = new TreeNode(rootNode->value);
	mirrorRootNode->leftChild = create_mirror_flip(rootNode->rightChild);
	mirrorRootNode->rightChild = create_mirror_flip(rootNode->leftChild);

	return mirrorRootNode;
}

void inOrderTraversal(TreeNode *rootNode)
{
	if (rootNode)
	{
		inOrderTraversal(rootNode->leftChild);
		std::cout << rootNode->value << " ";
		inOrderTraversal(rootNode->rightChild);
	}
}

int main()
{
	TreeNode *rootNode = nullptr;

	int nodeValues[] = {5, 3, 7, 2, 4, 6, 8};
	for (int val : nodeValues)
	{
		insertNode(rootNode, val);
	}

	std::cout << "Original Tree : ";
	inOrderTraversal(rootNode);
	std::cout << "\n";

	TreeNode *mirrorRootNode = create_mirror_flip(rootNode);

	std::cout << "Mirrored Tree : ";
	inOrderTraversal(mirrorRootNode);
	std::cout << "\n";

	return 0;
}
