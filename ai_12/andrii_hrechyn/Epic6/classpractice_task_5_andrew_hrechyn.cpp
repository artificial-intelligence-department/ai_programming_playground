#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::stack<TreeNode*> nodes;
    nodes.push(root);
    TreeNode* prev = nullptr;

    while (!nodes.empty()) {
        TreeNode* current = nodes.top();

        if (current->left == nullptr && current->right == nullptr) {
            nodes.pop();
            prev = current;
        } else if (prev == nullptr || prev->left == current || prev->right == current) {
            if (current->left != nullptr) {
                current->value += current->left->value;
                nodes.push(current->left);
            }
            if (current->right != nullptr) {
                current->value += current->right->value;
                nodes.push(current->right);
            }
        } else {
            nodes.pop();
            prev->value += current->value;
            prev = current;
        }
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

    cout << "sum of vuzol:\n";
    cout << "vuzol 1: " << root->value << "\n";
    cout << "vuzol 2: " << root->left->value << "\n";
    cout << "vuzol 3: " << root->right->value << "\n";
    cout << "vuzol 4: " << root->left->left->value << "\n";
    cout << "vuzol 5: " << root->left->right->value << "\n";
    cout << "vuzol 6: " << root->right->left->value << "\n";
    cout << "vuzol 7: " << root->right->right->value << "\n";

    return 0;
}
