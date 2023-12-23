#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функція для обчислення суми підвузлів і збереження результату у батьківському вузлі
void tree_sum(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    // Рекурсивно викликаємо функцію для лівого і правого піддерев
    tree_sum(root->left);
    tree_sum(root->right);

    if (root->left != nullptr) {
        root->data += root->left->data;
    }
    if (root->right != nullptr) {
        root->data += root->right->data;
    }
}

// Функція для виведення значень дерева в порядку post-order
void printTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    printTree(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Tree before calculating the sum of subnodes: ";
    printTree(root);
    cout << endl;

    // Виклик функції для обчислення суми підвузлів
    tree_sum(root);

    cout << "Tree after calculating the sum of subnodes: ";
    printTree(root);
    cout << endl;

    return 0;
}
