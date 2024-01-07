#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void tree_sum(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<TreeNode*> stackOfNode;
    TreeNode* current = root;
    TreeNode* previous = nullptr;

    while (current != nullptr || !stackOfNode.empty())
    {
        while (current != nullptr)
        {
            stackOfNode.push(current);
            current = current->left;
        }

        current = stackOfNode.top();

        if ((current->left == nullptr && current->right == nullptr) || (previous != nullptr && (previous == current->right || current->right == nullptr)))
        {
            stackOfNode.pop();

            int sum = current->data;
            if (current->left != nullptr)
            {
                sum += current->left->data;
            }
            if (current->right != nullptr)
            {
                sum += current->right->data;
            }

            current->data = sum;

            previous = current;
            current = nullptr;
        }
        else
        {
            current = current->right;
        }
    }
}

void printBinaryTree(TreeNode* root)
{
    if (root != nullptr)
    {
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty())
        {
            int levelSize = nodesQueue.size();
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode* current = nodesQueue.front();
                nodesQueue.pop();

                cout << current->data << " ";

                if (current->left != nullptr)
                {
                    nodesQueue.push(current->left);
                }
                if (current->right != nullptr)
                {
                    nodesQueue.push(current->right);
                }
            }
            cout << endl;
        }
    }
}

int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(1);

    cout << "Original binary tree:\n";
    printBinaryTree(root);

    tree_sum(root);

    cout << "\nTree after sums:\n";
    printBinaryTree(root);

    return 0;
}

