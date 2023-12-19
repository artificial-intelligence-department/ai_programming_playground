#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode *mirror = new TreeNode(root->val);

    mirror->left = create_mirror_flip(root->right);
    mirror->right = create_mirror_flip(root->left);

    return mirror;
}

void print_tree_inorder(TreeNode *root) 
{
    if (root != nullptr) 
    {
        print_tree_inorder(root->left);
        cout << root->val << " ";
        print_tree_inorder(root->right);
    }
}

int main() 
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original Tree: ";
    print_tree_inorder(root);
    cout << endl;

    TreeNode *mirror_root = create_mirror_flip(root);
    cout << "Mirrored Tree: ";
    print_tree_inorder(mirror_root);
    cout << endl;
}
