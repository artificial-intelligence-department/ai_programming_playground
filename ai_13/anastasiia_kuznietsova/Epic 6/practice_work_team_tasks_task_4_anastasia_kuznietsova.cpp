#include <iostream>
using namespace std;

struct TreeNode
{
    int number;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : number(x), left(nullptr), right(nullptr) {}
};

TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if ((root->left == nullptr) && (root == nullptr))
    {
        return 0;
    }

    TreeNode *mirrored = new TreeNode{root->number};
    mirrored->left = create_mirror_flip(root->right);
    mirrored->right = create_mirror_flip(root->left);

    cout << root->number << ' ';

    return mirrored;
}

int main()
{

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(2);
    TreeNode *mirroredtree = create_mirror_flip(root);

    return 0;
}