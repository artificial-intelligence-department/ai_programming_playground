#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    TreeNode* temp = root->left;
    root->left = create_mirror_flip(root->right);
    root->right = create_mirror_flip(temp);

    return root;
}

void print_tree(TreeNode* root) {
    if (root) {
        print_tree(root->left);
        cout << root->data << " ";
        print_tree(root->right);
    }
}

void delete_tree(TreeNode* root) {
    if (root) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
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

    cout << "Original Tree: ";
    print_tree(root);
    cout << endl;

    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "Mirrored Tree: ";
    print_tree(mirroredTree);
    cout << endl;

    return 0;
}
