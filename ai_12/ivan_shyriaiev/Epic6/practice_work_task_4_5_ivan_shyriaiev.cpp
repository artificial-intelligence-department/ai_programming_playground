#include <iostream>
using namespace std;

struct node {
    int key;
    node* left;
    node* right;

    node(int value) : key(value), left(nullptr), right(nullptr) {}
};
void addnode(node* &root, int key)
{
    if (root == nullptr){
        root = new node(key);
        return;
    }

    if (key < root->key){
        addnode(root->left, key);
    }
    else{
        addnode(root->right, key);
    }
}
node* mirrorTree(node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    node* mirror_root = new node(root->key);

    mirror_root->left = mirrorTree(root->right);
    mirror_root->right = mirrorTree(root->left);

    return mirror_root;
}

void print_inorder(node* root) {
    if (root == nullptr) {
        return;
    }
    print_inorder(root->left);
    cout << root->key << " ";
    print_inorder(root->right);
    
}

void tree_sum(node *root){
    int sum = 0;

    if (root == nullptr || (root->left == nullptr&&root->right == nullptr)){
        return;
    }

    if (root->left!=nullptr&&root->right!=nullptr){

       sum = root->left->key + root->right->key;
       root->key = sum;

    }

    tree_sum(root->left);
    tree_sum(root->right);
}

int main() {
    node* tree;

    addnode(tree, 5);     //5
    addnode(tree, 6);   //4  6
    addnode(tree, 4);  //3
    addnode(tree, 2); //2
    addnode(tree, 3);


    cout << "Regular: \n";
    print_inorder(tree);
    cout << "\n\n";

    node* mirrored = mirrorTree(tree);

    cout << "mirrored: \n";
    print_inorder(mirrored);
    cout << "\n\ntree after sum: ";

    tree_sum(tree);
    print_inorder(tree);

    return 0;
}
