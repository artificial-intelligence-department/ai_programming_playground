#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* Tree(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void printInorder(Node* node);

Node* swapLeftRight(Node* root) {
    if (root == NULL)
        return root;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if (root->left)
        swapLeftRight(root->left);
    if (root->right)
        swapLeftRight(root->right);
    return root;
}

int main() {
    Node *root = Tree(1);
    root->left = Tree(2);
    root->right = Tree(3);
    root->left->left = Tree(4);
    root->left->right = Tree(5);

    cout << "Inorder print of tree: ";
    printInorder(root);

    root = swapLeftRight(root);

    cout << "\nInorder print of mirrored tree: ";
    printInorder(root);

    return 0;
}

void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}