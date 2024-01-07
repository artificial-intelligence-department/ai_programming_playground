#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


void print_tree(TreeNode* root) {
    if (root) {
        print_tree(root->left);
        cout << root->data << " ";
        print_tree(root->right);
    }
}

void calculate_tree_sum(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return;
    }

    calculate_tree_sum(root->left);
    calculate_tree_sum(root->right);

    root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original Tree: ";
    print_tree(root);
    cout << endl;

    calculate_tree_sum(root);
    cout << "Tree after Sum Calculation: ";
    print_tree(root);
    cout << endl;

    return 0;
}
