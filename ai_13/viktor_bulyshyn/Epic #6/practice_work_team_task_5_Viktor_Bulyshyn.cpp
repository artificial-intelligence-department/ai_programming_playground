#include <iostream>

// Визначення структури TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функція для запису суми підвузлів кожному батьківському вузлу
void tree_sum(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Рекурсивний виклик для лівого та правого піддерева
    tree_sum(root->left);
    tree_sum(root->right);

    // Якщо вузол не є листком, обчислити та записати суму підвузлів
    if (root->left != nullptr) {
        root->data += root->left->data;
    }
    if (root->right != nullptr) {
        root->data += root->right->data;
    }
}

// Функція для виведення бінарного дерева (в порядку обходу)
void print_tree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    print_tree(root->left);
    std::cout << root->data << " ";
    print_tree(root->right);
}

int main() {
    // Створення бінарного дерева:   1
    //                               / \
    //                              2   3
    //                             / \
    //                            4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Запис суми підвузлів кожному батьківському вузлу
    tree_sum(root);

    // Виведення результату
    std::cout << "Tree with sums: ";
    print_tree(root);
    std::cout << std::endl;

    return 0;
}
