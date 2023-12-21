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

void in_order_traversal(TreeNode* root) {
    if (root != nullptr) {
        in_order_traversal(root->left);
        std::cout << root->data << " ";
        in_order_traversal(root->right);
    }
}


void tree_sum(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return; 
    }

    tree_sum(root->left);
    tree_sum(root->right);

    root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
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

    tree_sum(root);

    std::cout << "Tree After Sum Calculation : ";
    in_order_traversal(root);
    std::cout << std::endl;

    return 0;
}
