#include <iostream>

using namespace std;

struct TreeNode {
    int value=0;
    TreeNode* left=nullptr;
    TreeNode* right=nullptr;
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) { return root; }
    TreeNode* leaf=new TreeNode;
    leaf->value=root->value;
    leaf->left=create_mirror_flip(root->right);
    leaf->right=create_mirror_flip(root->left);
    return leaf;
}

void tree_sum(TreeNode* root) {
    if(root) {
        tree_sum(root->left);
        tree_sum(root->right);
        if ((!root->left) && (!root->right)) return;
        int left=((root->left!=nullptr)?root->left->value:0);
        int right=((root->right!=nullptr)?root->right->value:0);
        root->value=left+right;
    }
}

void print_tree(TreeNode* tree) {
    if (tree) {
        cout << tree->value << ' ';
        print_tree(tree->left);
        print_tree(tree->right);
    }
}

int main() {
    TreeNode* tree=new TreeNode;
    tree->value=7;
    tree->left=new TreeNode;
    tree->left->value=6;
    tree->right=new TreeNode;
    tree->right->value=5;
    tree->left->left=new TreeNode;
    tree->left->left->value=4;
    tree->left->right=new TreeNode;
    tree->left->right->value=3;
    tree->right->left=new TreeNode;
    tree->right->left->value=2;
    tree->right->right=new TreeNode;
    tree->right->right->value=1;
    print_tree(tree);
    cout << '\n';
    TreeNode* mirroredTree=create_mirror_flip(tree);
    print_tree(mirroredTree);
    cout << '\n';
    tree_sum(tree);
    print_tree(tree);
    cout << '\n';
    delete tree;
    delete mirroredTree;
    return 0;
}