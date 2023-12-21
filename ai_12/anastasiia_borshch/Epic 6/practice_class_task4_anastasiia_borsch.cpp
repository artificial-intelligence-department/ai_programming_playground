#include <iostream>
#include <queue>
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
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode* mirroredNode = new TreeNode(root->data);
    queue<TreeNode*> originalQueue, mirroredQueue;

    originalQueue.push(root);
    mirroredQueue.push(mirroredNode);

    while (!originalQueue.empty())
    {
        TreeNode* originalFront = originalQueue.front();
        TreeNode* mirroredFront = mirroredQueue.front();

        originalQueue.pop();
        mirroredQueue.pop();

        if (originalFront->right)
        {
            mirroredFront->left = new TreeNode(originalFront->right->data);
            originalQueue.push(originalFront->right);
            mirroredQueue.push(mirroredFront->left);
        }

        if (originalFront->left)
        {
            mirroredFront->right = new TreeNode(originalFront->left->data);
            originalQueue.push(originalFront->left);
            mirroredQueue.push(mirroredFront->right);
        }
    }

    return mirroredNode;
}

void correctOutput(TreeNode* root)
{
    if (root != nullptr)
    {
        correctOutput(root->left);
        cout << root->data << " ";
        correctOutput(root->right);
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(11);
    root->left->right = new TreeNode(26);
    root->left->right->left = new TreeNode(32);
    root->right = new TreeNode(82);
    root->right->left = new TreeNode(95);

    cout << "Original binary tree: ";
    correctOutput(root);
    cout << endl;

    TreeNode* mirroredTree = create_mirror_flip(root);

    cout << "Mirrored binary tree: ";
    correctOutput(mirroredTree);
    cout << endl;

    return 0;
}
