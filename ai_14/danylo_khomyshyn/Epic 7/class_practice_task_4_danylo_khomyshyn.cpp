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

    // Створення нового вузла
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

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Оригінальне дерево: ";
    printTree(root);
    cout << endl;

    TreeNode* mirroredRoot = create_mirror_flip(root);

    cout << "Віддзеркалене дерево: ";
    printTree(mirroredRoot);
    cout << endl;

    destroyTree(root);
    destroyTree(mirroredRoot);

    return 0;
}