#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int number;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : number(value), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode *root)
{
    if (!root)
    {
        return;
    }

    stack<TreeNode *> tree;
    TreeNode *current = nullptr;

    while (root || !tree.empty())
    {
        while (root)
        {
            tree.push(root);
            root = root->left;
        }

        root = tree.top();
        if (!root->right || root->right == current)
        {
            if (root->left)
            {
                root->number += root->left->number;
            }
            if (root->right)
            {
                root->number += root->right->number;
            }

            tree.pop();
            current = root;
            root = nullptr;
        }
        else
        {
            root = root->right;
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(9);
    root->right = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(2);
    root->left->left = new TreeNode(8);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);

    tree_sum(root);

    cout << "   " << root->number << "\n";
    cout << "  /  \\"
         << "\n";
    cout << " " << root->right->number << "    " << root->left->number << "\n";
    cout << "/ \\   / \\"
         << "\n";
    cout << root->left->left->number << " " << root->left->right->number << "   " << root->right->left->number << " " << root->right->right->number << "\n";

    return 0;
}