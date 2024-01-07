#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

void SumCalc(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    SumCalc(root->left);
    SumCalc(root->right);

    if (root->left != nullptr || root->right != nullptr)
    {
        int leftsum;
        if (root->left != nullptr)
        {
            leftsum = root->left->val;
        }
        else
        {
            leftsum = 0;
        }
        int rightsum;
        if (root->right != nullptr)
        {
            rightsum = root->right->val;
        }
        else
        {
            rightsum = 0;
        }
        root->val = leftsum + rightsum;
    }
}

void print_tree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Рекурсивно виводимо ліве піддерево, поточний вузол і праве піддерево
    print_tree(root->left);
    cout << root->val << " ";
    print_tree(root->right);
}

int main()
{
    // Приклад використання
    TreeNode *root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);

    root->right = new TreeNode(20);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(22);

    cout << "Default: ";
    print_tree(root);
    cout << endl;

    SumCalc(root);

    cout << "Tree of the sums: ";
    print_tree(root);
    cout << endl;

    return 0;
}