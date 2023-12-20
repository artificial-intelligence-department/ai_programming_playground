#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *lChild;
    TreeNode *rChild;

    TreeNode(int val) : data(val), lChild(nullptr), rChild(nullptr) {}
};

TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *newRoot = new TreeNode(root->data);

    newRoot->rChild = create_mirror_flip(root->lChild);
    newRoot->lChild = create_mirror_flip(root->rChild);

    return newRoot;
}

void printTree(TreeNode *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        printTree(node->lChild);
        printTree(node->rChild);
    }
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->lChild = new TreeNode(6);
    root->lChild->rChild = new TreeNode(7);
    root->lChild->lChild = new TreeNode(4);
    root->rChild = new TreeNode(12);

    cout << "Original Tree:" << endl;
    printTree(root);
    cout << endl;

    TreeNode *mirroredTree = create_mirror_flip(root);

    cout << "Mirrored Tree:" << endl;
    printTree(mirroredTree);
    cout << endl;

    return 0;
}

