#include <iostream>

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

    TreeNode* mirroredRoot = new TreeNode(root->data);
    mirroredRoot->left = create_mirror_flip(root->right);
    mirroredRoot->right = create_mirror_flip(root->left);

    return mirroredRoot;
}

void print_tree(TreeNode* root) {
    if (root != nullptr) {
        print_tree(root->left);
        std::cout << root->data << " ";
        print_tree(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Original tree: ";
    print_tree(root);
    std::cout << std::endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);

    std::cout << "Mirrored tree: ";
    print_tree(mirroredRoot);
    std::cout << std::endl;

    return 0;
}
