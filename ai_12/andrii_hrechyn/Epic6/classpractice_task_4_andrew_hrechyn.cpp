#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* createnode(int val) {
    return new TreeNode(val);
}

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* mirroredNode = createnode(root->data);
    mirroredNode->left = create_mirror_flip(root->right);
    mirroredNode->right = create_mirror_flip(root->left);

    return mirroredNode;
}

void printTree(TreeNode* root, int level = 0) {
    if (root != nullptr) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++) cout << "   ";
        cout << root->data << "\n";
        printTree(root->left, level + 1);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "BST before reflection:\n";
    printTree(root);

    TreeNode* mirroredRoot = create_mirror_flip(root);

    cout << "\nBST after reflection:\n";
    printTree(mirroredRoot);

    delete root;
    delete mirroredRoot;

    return 0;
}