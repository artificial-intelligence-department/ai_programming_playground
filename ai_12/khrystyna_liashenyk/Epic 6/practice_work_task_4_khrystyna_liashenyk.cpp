#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode *create_mirror_flip(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode *newNode = new TreeNode(root->data);
    newNode->left = create_mirror_flip(root->right);
    newNode->right = create_mirror_flip(root->left);

    return newNode;
}

void inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Original tree : ";
    inorderTraversal(root);
    cout << endl;

    TreeNode *mirrorTree = create_mirror_flip(root);

    cout << "Mirror-flipped tree : ";
    inorderTraversal(mirrorTree);
    cout << endl;

    return 0;
}
