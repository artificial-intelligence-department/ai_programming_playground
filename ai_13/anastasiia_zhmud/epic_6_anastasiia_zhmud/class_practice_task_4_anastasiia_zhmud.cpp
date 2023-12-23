#include <iostream>
using namespace std;

struct Tree {
    int val;
    Tree* left;
    Tree* right;
    Tree(int value) : val(value), left(nullptr), right(nullptr) {}
};
void print(Tree* root, int space=0) {
    int count = 2;
    if (root == nullptr) {
        return;
    }
    space += count;

    print(root->right, space);
    cout << endl;

    for (int i = count; i < space; i++) {
        cout << " ";
    }
    cout << root->val << "\n";

    print(root->left, space);
}
Tree* create_mirror_flip(Tree* root) {
    if (root == nullptr) {
        return nullptr;
    }
    Tree* mirror = new Tree(root->val);
    mirror->left = create_mirror_flip(root->right);
    mirror->right = create_mirror_flip(root->left);
    return mirror;
}

int main() {
    Tree* root = new Tree(1);
    root->left = new Tree(5);
    root->right = new Tree(3);
    root->left->left = new Tree(1);
    root->left->right = new Tree(4);
    cout << "Entrance tree: " << endl;
    print(root);
    Tree* mirrorRoot = create_mirror_flip(root);
    Tree* mirroredTree = create_mirror_flip(root);
    cout << "Mirrored tree:" << endl;
    print(mirroredTree); 
}