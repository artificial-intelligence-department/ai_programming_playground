#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create_mirror_flip(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode *mirror = new TreeNode(root->val);
    mirror->left = create_mirror_flip(root->right);
    mirror->right = create_mirror_flip(root->left);

    return mirror;
}

void printTree(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Створення вхідного дерева
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Друк вхідного дерева
    cout << "Input Tree: ";
    printTree(root);
    cout << endl;

    // Створення зеркального дерева
    TreeNode *mirrorRoot = create_mirror_flip(root);

    // Друк зеркального дерева
    cout << "Mirror Tree: ";
    printTree(mirrorRoot);
    cout << endl;

    return 0;
}
