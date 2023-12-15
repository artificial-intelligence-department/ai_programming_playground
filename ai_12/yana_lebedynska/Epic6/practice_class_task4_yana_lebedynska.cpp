#include <iostream>
using namespace std;

struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* create_mirror_flip(TreeNode* root)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    TreeNode* mirroredNode = new TreeNode(root->data);

    mirroredNode->left = create_mirror_flip(root->right);
    mirroredNode->right = create_mirror_flip(root->left);

    return mirroredNode;
}

void CorrectOutput(TreeNode* root)
{
    if(root != nullptr)
    {
        CorrectOutput(root->left);
        cout << root->data << " ";
        CorrectOutput(root->right);
    }
}

int main()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(2);
    root->right = new TreeNode(22);
    root->right->left = new TreeNode(11);

    cout << "Original binary tree: ";
    CorrectOutput(root);
    cout << endl;

    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "Mirrored binary tree: ";
    CorrectOutput(mirroredTree);
    cout << endl;

    return 0;
}
