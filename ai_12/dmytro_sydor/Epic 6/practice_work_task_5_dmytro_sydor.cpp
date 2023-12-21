#include <iostream>
#include <iostream>

// Структура для представлення вузла дерева
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
        int lSum;
        if (root->left != nullptr)
        {
            lSum = root->left->val;
        }
        else
        {
            lSum = 0;
        }
        int rSum;
        if (root->right != nullptr)
        {
            rSum = root->right->val;
        }
        else
        {
            rSum = 0;
        }
        root->val = lSum + rSum;
    }
}

// Функція для виведення дерева на екран
void print_tree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Рекурсивно виводимо ліве піддерево, поточний вузол і праве піддерево
    print_tree(root->left);
    std::cout << root->val << " ";
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

    /*
                    10

            5               20

        1       7       12      22

    */

    std::cout << "Original: ";
    print_tree(root);
    std::cout << std::endl;

    SumCalc(root);

    /*
                   42

           8               34

       1       7       12      22

   */

    std::cout << "Tree od sums: ";
    print_tree(root);
    std::cout << std::endl;

    return 0;
}
