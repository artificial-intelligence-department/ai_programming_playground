#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *newRoot = new TreeNode(root->val);

    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

void print_tree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    print_tree(root->left);
    cout << root->val << " ";
    print_tree(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(15);
    root->left->left = new TreeNode(245);
    root->left->right = new TreeNode(17);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(90);

    cout << "Original: ";
    print_tree(root);
    cout << endl;

    TreeNode *mirroredTree = create_mirror_flip(root);

    cout << "Mirrored: ";
    print_tree(mirroredTree);
    cout << endl;

    return 0;
}