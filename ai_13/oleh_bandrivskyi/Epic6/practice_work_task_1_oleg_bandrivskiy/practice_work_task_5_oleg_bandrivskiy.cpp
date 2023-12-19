#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = tree_sum(root->left);
    int rightSum = tree_sum(root->right);

    root->data += leftSum + rightSum;

    return root->data;
}

void print_tree(TreeNode* root) {
    if (root != nullptr) {
        print_tree(root->left);
        cout << root->data << " ";
        print_tree(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    print_tree(root);
    cout << endl;

    tree_sum(root);

    cout << "Modified tree: ";
    print_tree(root);
    cout << endl;

    return 0;
}
