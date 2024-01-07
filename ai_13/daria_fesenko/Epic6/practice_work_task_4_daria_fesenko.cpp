#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Оригінальне бінарне дерево: ";
    printTree(root);
    std::cout << std::endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);
    std::cout << "Віддзеркалене бінарне дерево: ";
    printTree(mirroredRoot);
    std::cout << std::endl;

    return 0;
}
