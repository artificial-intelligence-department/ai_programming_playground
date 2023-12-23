#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *lChild;
    TreeNode *rChild;

    TreeNode(int val) : data(val), lChild(nullptr), rChild(nullptr) {}
};

int tree_sum(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return 0;
    }

    int leftSum = tree_sum(root->lChild);
    int rightSum = tree_sum(root->rChild);

    if (root->lChild|| root->rChild) 
    {
        root->data += leftSum + rightSum;
    }

    return root->data;
}

void printTree(TreeNode* node) 
{
    if (node != nullptr) 
    {
        cout << node->data << " ";
        printTree(node->lChild);
        printTree(node->rChild);
    }
}

int main() 
{
    TreeNode* root = new TreeNode(8);
    root->lChild = new TreeNode(6);
    root->rChild = new TreeNode(10);
    root->lChild->lChild = new TreeNode(4);
    root->lChild->rChild = new TreeNode(7);
    root->rChild->lChild = new TreeNode(9);
    root->rChild->rChild = new TreeNode(11);
    cout << "Original Tree:" << endl;
    printTree(root);
    cout << endl;
    tree_sum(root);
    cout << "Updated Tree:" << endl;
    printTree(root);

    return 0;
}
