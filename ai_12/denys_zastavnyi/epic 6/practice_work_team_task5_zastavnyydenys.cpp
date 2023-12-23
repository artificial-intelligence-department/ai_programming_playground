#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

void tree_sum(TreeNode* root) {
    stack<TreeNode*> nodes;
    TreeNode* current = root;
    TreeNode* prev = nullptr;

    while (current != nullptr || !nodes.empty()) {
        while (current != nullptr) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        nodes.pop();

        if (current->right == nullptr || current->right == prev) {
            int sum = 0;
            if (current->left != nullptr) {
                sum += current->left->data;
            }
            if (current->right != nullptr) {
                sum += current->right->data;
            }
            current->data += sum;

            prev = current;
            current = nullptr;
        } else {
            nodes.push(current);
            current = current->right;
        }
    }
}

int main() {
    TreeNode* root = createTree();

    cout << "Original Tree (Inorder): ";
    printTree(root);
    cout << endl;

    tree_sum(root);

    cout << "Modified Tree (Inorder): ";
    printTree(root);
    cout << endl;

 
    return 0;
}
