#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}

};

void CreateATree(TreeNode*& node, int value){
    if (node == nullptr){
        node = new TreeNode(value);
    }
    else{
        if (value < node->data){
            CreateATree(node->left, value);
        }
        else if (value > node->data){
            CreateATree(node->right, value);
        }
    }
}

void CreateTree(TreeNode*& root, const vector<int>& vec){
    for (int value : vec){
        CreateATree(root, value);
    }
}

void printTree(TreeNode* node){
    if (node != nullptr){
        printTree(node->left);
        cout << node->data << " ";
        printTree(node->right);
    }
}

TreeNode* CreateMirrorFlip(TreeNode* node){
    if (node == nullptr){
        return nullptr;
    }

    TreeNode* leftSubtree = CreateMirrorFlip(node->left);
    TreeNode* rightSubtree = CreateMirrorFlip(node->right);

    node->left = rightSubtree;
    node->right = leftSubtree;

    return node;
}

void TreeOfSum(TreeNode*& node) {
    if (node == nullptr) {
        return;
    }

    int leftData = (node->left != nullptr) ? node->left->data : 0;
    int rightData = (node->right != nullptr) ? node->right->data : 0;

    TreeOfSum(node->left);
    TreeOfSum(node->right);

    node->data = leftData + rightData + node->data;
}

int main(){
    vector<int> vec = {11, 8, 4, 2, 3, 7, 5};
    TreeNode* root = nullptr;

    CreateTree(root, vec);
    cout << "original tree: ";
    printTree(root);

    TreeNode* reversed = CreateMirrorFlip(root);
    cout << endl << "reversed tree: ";
    printTree(reversed);

    TreeOfSum(root);
    cout << endl << "tree of sums: ";
    printTree(root);
    
    return 0;
}