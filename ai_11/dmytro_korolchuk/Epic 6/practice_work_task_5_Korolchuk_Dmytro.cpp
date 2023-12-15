#include <iostream>
using namespace std;

struct Tree{
    int data;
    Tree *right;
    Tree *left;

    Tree(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Tree* insertTree(Tree* root, int value) {
    if (root == nullptr) {
        return new Tree(value);
    }

    if (value < root->data) {
        root->left = insertTree(root->left, value);
    } else if (value > root->data) {
        root->right = insertTree(root->right, value);
    }

    return root;
}
int calculateSubtreeSum(Tree* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftSum = calculateSubtreeSum(node->left);
    int rightSum = calculateSubtreeSum(node->right);

    int subtreeSum = node->data + leftSum + rightSum;

    node->data = subtreeSum;
    
    return subtreeSum;
}
void printTree(Tree* node) {
    if (node != nullptr) {
        printTree(node->left);
        cout << node->data << " ";
        printTree(node->right);
    }
}
int main() {
    Tree* root = nullptr;

    root = insertTree(root, 5);
    insertTree(root, 3);
    insertTree(root, 7);
    insertTree(root, 6);
    insertTree(root, 2);
    insertTree(root, 4);

    printTree(root);
    cout<<endl;

    calculateSubtreeSum(root);

    printTree(root);
    cout<<endl;
}