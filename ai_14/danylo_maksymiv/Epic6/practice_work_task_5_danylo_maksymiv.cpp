#include <iostream>
using namespace std;

struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

int calculateSubtreeSum(TreeNode* node) 
{
    if (node == nullptr) 
    {
        return 0;
    }

    int leftSum = calculateSubtreeSum(node->left);
    int rightSum = calculateSubtreeSum(node->right);

    if (node->left || node->right) 
    {
        node->data += leftSum + rightSum;
    }

    return node->data;
}

void printTree(TreeNode* node) 
{
    if (node != nullptr) 
    {
        cout << node->data << " ";
        printTree(node->left);
        printTree(node->right);
    }
}

int main() 
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    printTree(root);
    cout << endl;

    calculateSubtreeSum(root);
    printTree(root);
}




 // Дерево до обчислення суми підвузлів:
    //      10
    //     /  \
    //    5    15
    //   / \   / \
    //  3   7 12  18
