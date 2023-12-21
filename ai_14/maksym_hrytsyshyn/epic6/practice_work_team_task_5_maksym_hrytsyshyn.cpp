#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->value = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->value << " ";
    printTree(root->left);
    printTree(root->right);
}



void tree_sum(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    if (root->left != nullptr) {
        tree_sum(root->left);
        root->value += root->left->value;
    }
    if (root->right != nullptr) {
        tree_sum(root->right);
        root->value += root->right->value;
    }
}


int main() {
    TreeNode* root = createNode(1);
    
    root->left = createNode(2);
    root->right = createNode(3);
    
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    printTree(root);

    tree_sum(root);
    cout << "The tree with the sum of its children: ";
    printTree(root);
}