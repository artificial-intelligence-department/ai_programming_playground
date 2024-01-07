#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;  // Return root outside the if-else block
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        if (current->left != nullptr || current->right != nullptr) {
            int leftSum = (current->left != nullptr) ? current->left->data : 0;
            int rightSum = (current->right != nullptr) ? current->right->data : 0;

            current->data = leftSum + rightSum;
        }

        if (current->left != nullptr) {
            nodeQueue.push(current->left);
        }
        if (current->right != nullptr) {
            nodeQueue.push(current->right);
        }
    }
}

int main() {
    TreeNode* root = nullptr;
    int elements[] = {10, 5, 15, 3, 7, 12, 20};

    for (int element : elements) {
        root = insert(root, element);
    }

    cout << "Original Tree: ";
    inorderTraversal(root);
    cout << endl;

    tree_sum(root);

    cout << "Tree after sum calculation: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
