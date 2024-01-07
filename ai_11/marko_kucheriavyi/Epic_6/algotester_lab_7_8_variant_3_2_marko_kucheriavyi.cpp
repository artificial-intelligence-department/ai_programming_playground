#include <iostream>
using namespace std;

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode* createNode(int value){
        TreeNode* newNode = new TreeNode;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

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

    int size(TreeNode* node){
        if (node == nullptr){
            return 0;
        }

        return size(node->left) + size(node->right) + 1;
    }

    void print(TreeNode* node){
        if (node != nullptr){
            print(node->left);
            cout << node->value << " ";
            print(node->right);
        }
    }
};


int main(){
    int Q;
    cin >> Q;

    TreeNode* tree = nullptr;

    for (int i = 0; i < Q; i++){
        string question;
        cin >> question;

        if (question == "insert"){
            int value;
            cin >> value;
            tree = tree->insert(tree, value);
        }
        else if (question == "contains"){
            int value;
            cin >> value;
            cout << (tree->contains(tree, value) ? "Yes" : "No") << endl;
        } 
        else if (question == "size"){
            cout << tree->size(tree) << endl;
        }
        else if (question == "print"){
            tree->print(tree);
            cout << endl;
        }
    }

    return 0;
}