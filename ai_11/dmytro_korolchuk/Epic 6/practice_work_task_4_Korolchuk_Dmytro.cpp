#include <iostream>
using namespace std;

struct Tree{
    int data;
    Tree *right;
    Tree *left;

    Tree(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Tree* insertTree(Tree* root, int value) {
    if (root == nullptr) {
        return new Tree(value);
    }

    if (value < root->data) {
        root->left = insertTree(root->left, value);
    } else if (value > root->data) {
        root->right = insertTree(root->right, value);
    }

    return root;
}
Tree* create_mirror_flip(Tree* root){
    if(root == nullptr){
        return nullptr;
    }

    Tree* mirrorredTree = new Tree(root->data);

    mirrorredTree->left = create_mirror_flip(root->right);
    mirrorredTree->right = create_mirror_flip(root->left);

    return mirrorredTree;
}
void printTree(Tree* node) {
    if (node != nullptr) {
        printTree(node->left);
        cout << node->data << " ";
        printTree(node->right);
    }
}
int main() {
    Tree* root = nullptr;

    root = insertTree(root, 5);
    insertTree(root, 3);
    insertTree(root, 7);
    insertTree(root, 2);
    insertTree(root, 4);

    printTree(root);
    cout<<endl;

    Tree* mirrorredTree = create_mirror_flip(root);

    printTree(mirrorredTree);
    cout<<endl;
}