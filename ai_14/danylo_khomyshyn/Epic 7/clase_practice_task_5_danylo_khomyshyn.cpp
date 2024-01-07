#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int calculateSubtreeSum(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftSum = calculateSubtreeSum(root->left);
    int rightSum = calculateSubtreeSum(root->right);

    root->data += leftSum + rightSum;

    return root->data;
}

void tree_sum(TreeNode* root) {
    calculateSubtreeSum(root);
}

void printTree(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Оригінальне дерево: ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Дерево зі сумами підвузлів: ";
    printTree(root);
    cout << endl;

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}