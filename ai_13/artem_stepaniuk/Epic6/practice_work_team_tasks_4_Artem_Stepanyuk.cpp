#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* createMirror(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* mirroredNode = new TreeNode(root->data);
    mirroredNode->left = createMirror(root->right);
    mirroredNode->right = createMirror(root->left);

    return mirroredNode;
}

void printInOrder(TreeNode* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        std::cout << root->data << " ";
        printInOrder(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Оригінальне дерево (зворотній обхід): ";
    printInOrder(root);
    std::cout << std::endl;

    TreeNode* mirroredRoot = createMirror(root);

    std::cout << "Віддзеркалене дерево (зворотній обхід): ";
    printInOrder(mirroredRoot);
    std::cout << std::endl;


    return 0;
}