#include <iostream>

// Визначення структури TreeNode
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функція для віддзеркалення бінарного дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створення нового вузла з оберненими лівою і правою вітками
    TreeNode* mirroredRoot = new TreeNode(root->data);
    mirroredRoot->left = create_mirror_flip(root->right);
    mirroredRoot->right = create_mirror_flip(root->left);

    return mirroredRoot;
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

    // Віддзеркалення бінарного дерева
    TreeNode* mirroredRoot = create_mirror_flip(root);

    // Виведення вихідного та віддзеркаленого дерева
    std::cout << "Original Tree: ";
    print_tree(root);
    std::cout << std::endl;

    std::cout << "Mirrored Tree: ";
    print_tree(mirroredRoot);
    std::cout << std::endl;

    return 0;
}
