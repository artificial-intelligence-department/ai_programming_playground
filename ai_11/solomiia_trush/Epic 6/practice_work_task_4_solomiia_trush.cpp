#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* mirror_tree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    } else {
        TreeNode* mirror = new TreeNode;

        mirror->data = root->data; 
        mirror->left = mirror_tree(root->right);
        mirror->right = mirror_tree(root->left);

        return mirror;   
    }   
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    } else {    
        printTree(root->left);
        printTree(root->right);
                cout << root->data << " ";

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

    cout << "Original Tree : ";
    printTree(root);
    cout << endl;

    TreeNode* mirrorRoot = mirror_tree(root);

    cout << "Mirror Tree : ";
    printTree(mirrorRoot);
    cout << endl;

    deleteTree(root);
    deleteTree(mirrorRoot);

    return 0;
}