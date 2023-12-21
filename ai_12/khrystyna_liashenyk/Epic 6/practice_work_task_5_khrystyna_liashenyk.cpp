#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void calculateSubtreeSum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> nodes;
    TreeNode* current = root;
    TreeNode* prev = nullptr;

    while (current != nullptr || !nodes.empty()) {
        while (current != nullptr) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();

        if (current->left == nullptr && current->right == nullptr) {
            nodes.pop();
            prev = current;
            current = nullptr;
        } else if (current->right != nullptr && current->right != prev) {
            current = current->right;
        } else {
            TreeNode* temp = current;
            current = nullptr;
            nodes.pop();

            int sum = temp->data;
            if (temp->left != nullptr) {
                sum += temp->left->data;
            }
            if (temp->right != nullptr) {
                sum += temp->right->data;
            }

            temp->data = sum;
            prev = temp;
        }
    }
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);

    cout << "Original Binary Tree: ";
    inorderTraversal(root);
    cout << endl;

    calculateSubtreeSum(root);

    cout << "Tree after computing subtree sums: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
