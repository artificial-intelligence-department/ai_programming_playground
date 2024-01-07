#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->val);
    newRoot->right = create_mirror_flip(root->left);
    newRoot->left = create_mirror_flip(root->right);

    return newRoot;
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree: ";
    inorderTraversal(root);
    cout << endl;
    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "Mirrored tree: ";
    inorderTraversal(mirroredTree);
    cout << endl;

    return 0;
}
