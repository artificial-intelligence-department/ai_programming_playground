#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* Tree(int data) {
    Node* node = new Node();
    if (node == NULL) {
        cout << "Memory allocation failed" << endl;
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int updateTree(Node* node) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return node->data;
    int old_val = node->data;
    int left_sum  = updateTree(node->left);
    int right_sum = updateTree(node->right);
    node->data = left_sum + right_sum;
    return node->data + old_val;
}

int main() {
    Node* root = Tree(0);
    root->left = Tree(-12);
    root->right = Tree(13);
    root->left->left = Tree(4);
    root->left->right = Tree(0);
    root->right->left = Tree(1);
    root->right->right = Tree(-2);
    updateTree(root);
    cout << "Updated tree root value is: " << root->data << endl;
    return 0;
}
