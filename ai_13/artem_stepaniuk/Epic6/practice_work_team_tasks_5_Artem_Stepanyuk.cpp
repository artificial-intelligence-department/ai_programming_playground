#include <iostream>
#include <stack>

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void calculateSubtreeSum(BinaryTreeNode* root) {
    if (!root) {
        return;
    }

    std::stack<BinaryTreeNode*> nodes;
    BinaryTreeNode* current = root;
    BinaryTreeNode* prev = nullptr;

    while (current || !nodes.empty()) {
        while (current) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        nodes.pop();

        if (current->right && current->right != prev) {
            nodes.push(current);
            current = current->right;
        } else {
            current->value += (current->left ? current->left->value : 0) +
                              (current->right ? current->right->value : 0);

            prev = current;
            current = nullptr;
        }
    }
}

BinaryTreeNode* createSampleBinaryTree() {
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);

    return root;
}

void printBinaryTree(BinaryTreeNode* root) {
    if (!root) {
        return;
    }

    std::stack<BinaryTreeNode*> nodes;
    BinaryTreeNode* current = root;

    while (current || !nodes.empty()) {
        while (current) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        nodes.pop();

        std::cout << current->value << " ";

        current = current->right;
    }
}

int main() {
    BinaryTreeNode* root = createSampleBinaryTree();

    std::cout << "Дерево до зміни значень: ";
    printBinaryTree(root);
    std::cout << std::endl;

    calculateSubtreeSum(root);

    std::cout << "Дерево після зміни значень: ";
    printBinaryTree(root);
    std::cout << std::endl;


    return 0;
}