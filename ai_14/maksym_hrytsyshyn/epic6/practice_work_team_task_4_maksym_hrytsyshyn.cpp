#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    newNode->data = data ;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TreeNode *create_mirror_flip(TreeNode *root){
    if (root == nullptr) {
        return nullptr;
    }
    else {
        TreeNode* temp = createNode(root->data);
        temp->left = create_mirror_flip(root->right);
        temp->right = create_mirror_flip(root->left);

        return temp;
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}


int main() {
    TreeNode* root = createNode(1);
    
    root->left = createNode(2);
    root->right = createNode(3);
    
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    printTree(root);

    TreeNode* temp = create_mirror_flip(root);
    cout << "Mirror tree: ";
    printTree(temp);

    return 0;
}