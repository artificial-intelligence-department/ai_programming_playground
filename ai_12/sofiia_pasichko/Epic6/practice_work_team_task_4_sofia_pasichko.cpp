#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* mirror_flip_node = new TreeNode(root->data);
    mirror_flip_node->right = create_mirror_flip(root->left);
    mirror_flip_node->left = create_mirror_flip(root->right);
    return mirror_flip_node;
}

void print_tree(TreeNode *root)
{
    if (root != NULL) {
        print_tree(root->left);
        cout << root->data <<" ";
        print_tree(root->right);
    }
    return;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(11);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(17);

    TreeNode* mirrored_tree = create_mirror_flip(root);

    print_tree(root);
    cout << endl;
    print_tree(mirrored_tree);
    delete root;
    delete mirrored_tree;
    return 0;
}