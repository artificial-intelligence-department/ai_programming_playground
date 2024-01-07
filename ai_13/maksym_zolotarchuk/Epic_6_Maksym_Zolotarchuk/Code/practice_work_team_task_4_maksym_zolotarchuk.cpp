#include <iostream>
using namespace std;
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

TreeNode *createMirrorFlip(const TreeNode *rootNode)
{
    if (rootNode == nullptr)
    {
        return nullptr;
    }

    TreeNode *mirrorRootNode = new TreeNode(rootNode->value);
    mirrorRootNode->leftChild = createMirrorFlip(rootNode->rightChild);
    mirrorRootNode->rightChild = createMirrorFlip(rootNode->leftChild);

    return mirrorRootNode;
}

void inOrderTraversal(const TreeNode *rootNode)
{
    if (rootNode)
    {
        inOrderTraversal(rootNode->leftChild);
        cout << rootNode->value << " ";
        inOrderTraversal(rootNode->rightChild);
    }
}

void deleteTree(TreeNode *&rootNode)
{
    if (rootNode)
    {
        deleteTree(rootNode->leftChild);
        deleteTree(rootNode->rightChild);
        delete rootNode;
        rootNode = nullptr;
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

    cout << "Original Tree: ";
    inOrderTraversal(rootNode);
    cout << "\n";

    TreeNode *mirrorRootNode = createMirrorFlip(rootNode);

    cout << "Mirrored Tree: ";
    inOrderTraversal(mirrorRootNode);
    cout << "\n";

    // Очистка пам'яті після використання дерева
    deleteTree(rootNode);
    deleteTree(mirrorRootNode);

    return 0;
}
