//4 task 
#include <iostream>

// Структура вузла дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для віддзеркалення дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створення нового вузла, з дзеркально віддзеркаленими лівою і правою вітками
    TreeNode* mirroredNode = new TreeNode(root->data);
    mirroredNode->left = create_mirror_flip(root->right);
    mirroredNode->right = create_mirror_flip(root->left);

    return mirroredNode;
}

// Функція для виведення дерева на екран (в порядку обходу в глибину)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Рекурсивний вивід дерева (порядок: корінь, ліво, право)
    printTree(root->left);
    std::cout << root->data << " ";
    printTree(root->right);
}

int main() {
    // Створення початкового дерева:   
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Виведення початкового дерева
    std::cout << "Original Tree: ";
    printTree(root);
    std::cout << std::endl;

    // Створення дзеркально віддзеркаленого дерева
    TreeNode* mirroredRoot = create_mirror_flip(root);

    // Виведення дзеркально віддзеркаленого дерева
    std::cout << "Mirrored Tree: ";
    printTree(mirroredRoot);
    std::cout << std::endl;

    // Очищення пам'яті
    delete root;
    delete mirroredRoot;

    return 0;
}

