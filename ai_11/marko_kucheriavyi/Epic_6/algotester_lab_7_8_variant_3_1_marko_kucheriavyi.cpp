#include <iostream>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node with a given value
TreeNode* createNode(int value){
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a value into the binary search tree
TreeNode* insert(TreeNode* node, int value){
    if (node == nullptr){
        return createNode(value);
    }

    if (value < node->value){
        node->left = insert(node->left, value);
    } 
    else if (value > node->value){
        node->right = insert(node->right, value);
    }

    return node;
}

// Function to check if a value exists in the binary search tree
bool contains(const TreeNode* node, int value){
    if (node == nullptr){
        return false;
    }

    if (value == node->value){
        return true;
    } 
    else if (value < node->value){
        return contains(node->left, value);
    } 
    else{
        return contains(node->right, value);
    }
}

// Function to calculate the size (number of nodes) of the binary search tree
int size(TreeNode* node){
    if (node == nullptr){
        return 0;
    }

    return size(node->left) + size(node->right) + 1;
}

// Function to print the values in the binary search tree
void print(TreeNode* node){
    if (node != nullptr){
        print(node->left);
        cout << node->value << " ";
        print(node->right);
    }
}

int main() {
    int Q;
    cin >> Q;

    TreeNode* root = nullptr;

    for (int i = 0; i < Q; i++){
        string question;
        cin >> question;

        if (question == "insert"){
            int value;
            cin >> value;
            root = insert(root, value);
        } 
        else if (question == "contains"){
            int value;
            cin >> value;
            cout << (contains(root, value) ? "Yes" : "No") << endl;
        } 
        else if (question == "size"){
            cout << size(root) << endl;
        }
        else if (question == "print"){
            print(root);
            cout << endl;
        }
    }

    return 0;
}