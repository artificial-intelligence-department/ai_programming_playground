#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode *mirrorflip(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *mirroredRoot = new TreeNode(root->value);
    mirroredRoot->left = mirrorflip(root->right);
    mirroredRoot->right = mirrorflip(root->left);

    return mirroredRoot;
}

void tree_sum(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    stack<TreeNode *> nodeStack;
    TreeNode *current = root;
    TreeNode *previous = nullptr;

    while (current || !nodeStack.empty())
    {
        while (current)
        {
            nodeStack.push(current);
            current = current->left;
        }
        current = nodeStack.top();
        if (current->right && current->right != previous)
        {
            current = current->right;
        }
        else
        {
            int val = current->value;
            if (current->left)
            {
                val += current->left->value;
            }
            if (current->right)
            {
                val += current->right->value;
            }
            current->value = val;

            nodeStack.pop();
            previous = current;
            current = nullptr;
        }
    }
}

void printTree(const TreeNode *root)
{
    if (root != nullptr)
    {
        printTree(root->left);
        cout << root->value << " ";
        printTree(root->right);
    }
}

int main()
{

    TreeNode *tree = new TreeNode(2);
    tree->left = new TreeNode(5);
    tree->right = new TreeNode(8);
    tree->left->left = new TreeNode(11);
    tree->left->right = new TreeNode(14);

    cout << "Origin tree: ";
    printTree(tree);
    cout << endl;

    TreeNode *mirroredTree = mirrorflip(tree);

    cout << "Mirrored tree: ";
    printTree(mirroredTree);
    cout << endl;

    tree_sum(tree);
    cout << "Tree sum:" << endl;
    printTree(tree);

    return 0;
}