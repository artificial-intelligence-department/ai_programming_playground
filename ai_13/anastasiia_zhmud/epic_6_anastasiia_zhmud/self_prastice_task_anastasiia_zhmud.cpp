#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
void print(Node* root, int space=0) {
    int count = 2;
    if (root == nullptr) return;
    space += count;
    print(root->right, space);
    cout << endl;
    for (int i = count; i < space; i++) cout << " ";
    cout << root->data << "\n";
    print(root->left, space);
}
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
int getHeight(Node* root) {
    if (root == nullptr) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
bool isBalanced(Node* root) {
    if (root == nullptr) return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return true;
    return false;
}
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    print(root);
    if (isBalanced(root)) {
        cout << "Tree is balanced" << endl;
    } else {
        cout << "Tree isn`t balanced" << endl;
    }
    return 0;
}
