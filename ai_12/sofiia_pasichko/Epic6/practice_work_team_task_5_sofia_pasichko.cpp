#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TreeNode*> nodes;
    TreeNode* current = root;
    int sum = 0;

    while (current != nullptr || !nodes.empty()) {
        while (current != nullptr) {
            nodes.push(current);
            current = current->left;
        }

        current = nodes.top();
        nodes.pop();

        sum += current->data;
        current->data = sum;

        current = current->right;
    }
}

void print_tree(TreeNode *root)
{
    if (root != NULL) {
        print_tree(root->left);
        cout << root->data <<" ";
        print_tree(root->right);
    }
    return;
}

void delete_tree(TreeNode* root) {
    if (root != nullptr) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(17);

    print_tree(root);
    cout << endl;
    tree_sum(root);
    print_tree(root);
    cout << endl;

    delete_tree(root);

    return 0;
}