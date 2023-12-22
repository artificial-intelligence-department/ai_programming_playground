#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

int tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    int nodeSum = root->data + leftSum + rightSum;
    
    if (root->left || root->right) {
        root->data = leftSum + rightSum;
    }

    return nodeSum;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    } else {    
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    } else {    
        deleteTree(root->left);
        deleteTree(root->right);

        delete root;
    }
}

int main() {
    TreeNode* root = new TreeNode();
    root->data = 1;
    root->left = new TreeNode();
    root->left->data = 2;
    root->right = new TreeNode();
    root->right->data = 3;
    root->left->left = new TreeNode();
    root->left->left->data = 4;
    root->left->right = new TreeNode();
    root->left->right->data = 5;

    cout << "Original Tree Structure : ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Tree Structure after tree_sum : ";
    printTree(root);
    cout << endl;

    delete(root);

    return 0;
}