#include <iostream>

using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};


template <typename T>
TreeNode<T>* insert(TreeNode<T>* root, T value) {
    if (root == nullptr) {
        return new TreeNode<T>(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


template <typename T>
void printInOrder(TreeNode<T>* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}


template <typename T>
TreeNode<T>* mirrorFlip(TreeNode<T>* root) {
    if (root == nullptr) {
        return nullptr;
    }

    
    TreeNode<T>* temp = root->left;
    root->left = mirrorFlip(root->right);
    root->right = mirrorFlip(temp);

    return root;
}

int main() {
    
    TreeNode<int>* root = nullptr;

    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 6);
    insert(root, 9);

    
    cout << "Original Binary Tree (in-order): ";
    printInOrder(root);
    cout <<endl;

    
    TreeNode<int>* mirroredRoot = mirrorFlip(root);

    
    cout << "Mirrored Binary Tree (in-order): ";
    printInOrder(mirroredRoot);
    cout << endl;
    return 0;
    //            7                              
    //          /   \ 
    //         5     10      - Перше дерево
    //       /  \   /  \ 
    //      3    6  9   15
    //           
    //
    //            7
    //          /   \ 
    //         5    10      - Відзеркалене дерево
    //       /  \   /  \ 
    //      3    6  9   15
}
