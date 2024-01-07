#include <iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) 
        return nullptr;

    TreeNode* mirroredLeft = create_mirror_flip(root->right);
    TreeNode* mirroredRight = create_mirror_flip(root->left);

    TreeNode* mirroredRoot = new TreeNode(root->data);
    mirroredRoot->left = mirroredLeft;
    mirroredRoot->right = mirroredRight;

    return mirroredRoot;
}

void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
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

    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "start tree: ";
    printTree(root);
    cout << endl;

    cout << "mirored tree: ";
    printTree(mirroredTree);

    delete mirroredTree;
    delete root;

    return 0;
}
