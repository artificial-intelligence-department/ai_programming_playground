#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    if (value < root->data) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }


    TreeNode* mirroredRoot = new TreeNode(root->data);


    mirroredRoot->right = create_mirror_flip(root->left);
    mirroredRoot->left = create_mirror_flip(root->right);

    return mirroredRoot;
}

void in_order_traversal(TreeNode* root) {
    if (root != nullptr) {
        in_order_traversal(root->left);
        std::cout << root->data << " ";
        in_order_traversal(root->right);
    }
}

int main() {

    TreeNode* root = nullptr;


    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);


    std::cout << "Original Tree : ";
    in_order_traversal(root);
    std::cout << std::endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);

    std::cout << "Mirrored Tree : ";
    in_order_traversal(mirroredRoot);
    std::cout << std::endl;


    return 0;
}
