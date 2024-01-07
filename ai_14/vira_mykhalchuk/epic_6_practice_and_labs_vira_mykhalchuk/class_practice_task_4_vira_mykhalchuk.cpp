#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->data);

    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

void destroyTree(TreeNode* root) {
    if (root) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void printTree(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {

    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(50);
    root->right = new TreeNode(100);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(80);


    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);

    cout << "Mirrored tree: ";
    printTree(mirroredRoot);
    cout << endl;

    destroyTree(root);
    destroyTree(mirroredRoot);

    return 0;
}   