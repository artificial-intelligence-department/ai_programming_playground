#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root) {
    if (root == nullptr) 
        return;

    stack<TreeNode*> nodeStack;
    TreeNode* current = root;
    TreeNode* prev = nullptr;

    while (current != nullptr || !nodeStack.empty()) {
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        current = nodeStack.top();

        if (current->right != nullptr && current->right != prev) 
            current->data += current->right->data;

        nodeStack.pop();
        prev = current;
        current = nullptr;
    }
}

void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

int main() {


    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    tree_sum(root);
    cout << "sum nodes of binar tree: ";
    printTree(root);
    cout << endl;
    delete root;
    return 0;
}
