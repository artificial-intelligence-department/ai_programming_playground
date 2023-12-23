#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode *create_mirror_flip(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *newRoot = new TreeNode(root->val);

    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

void print_tree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    print_tree(root->left);
    std::cout << root->val << " ";
    print_tree(root->right);
}

int main()
{

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

    // Створюємо дзеркально віддзеркалене дерево
    TreeNode *mirroredTree = create_mirror_flip(root);

    std::cout << "Mirrored: ";
    print_tree(mirroredTree);
    std::cout << std::endl;

    return 0;
}
