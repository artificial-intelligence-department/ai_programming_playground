#include <iostream>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int n)
    {
        data = n;
        left = NULL;
        right = NULL;
    }
};

void printTree(TreeNode *root);
TreeNode *create_mirror_flip(TreeNode *root);
void tree_sum(TreeNode *root);

int main()
{
    cout << "TASK 4\n\n";

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    /*
         1
       /   \
      2      3
     / \    / \
    4   5  6   7
    */
    printTree(root);
    cout << endl;

    TreeNode* newRoot = create_mirror_flip(root);
    /*
         1
       /   \
      3      2
     / \    / \
    7   6  5   4
    */
    printTree(newRoot);
    cout << endl;

    cout << "\nTASK 5\n\n";
    tree_sum(root);
    /*
         22
       /    \
      9      13
     / \     / \
    4   5   6   7
    */
    printTree(root);
    cout << "\n\n";

    return 0;
}
void printTree(TreeNode *root) // Inorder Recursive Traversal
{
    if (root != NULL) {
        printTree(root->left);
        cout << root->data <<" ";
        printTree(root->right);
    }
    return;
}
TreeNode *create_mirror_flip(TreeNode *root)
{
    if(root)
    {
        TreeNode* newRoot = new TreeNode(root->data);

        newRoot->left = create_mirror_flip(root->right);
        newRoot->right = create_mirror_flip(root->left);

        return newRoot;
    }

    return NULL;
}
void tree_sum(TreeNode *root)
{   
    if(root == NULL)
    {
        cout << "Tree is empty!\n";
        return;
    }

    if(root->left)
    {
        tree_sum(root->left);
    }
    if(root->right)
    {
        tree_sum(root->right);
    }

    if(root->left || root->right)
    {
        root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
    }

    return;
}
