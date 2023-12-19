#include <iostream>

// Структура вузла бінарного дерева
struct TreeNode 
{
    int data;         // Значення вузла
    TreeNode* left;    // Вказівник на ліву вітку
    TreeNode* right;   // Вказівник на праву вітку
    // Конструктор для ініціалізації вузла з заданим значенням та вказівниками на ліву та праву вітки
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для створення дерева-дзеркала
TreeNode* create_mirror(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return nullptr;
    }

    // Створюємо новий вузол з тим же значенням
    TreeNode* newRoot = new TreeNode(root->data);

    // Рекурсивно обертаємо праву і ліву вітки
    newRoot->left = create_mirror(root->right);
    newRoot->right = create_mirror(root->left);

    return newRoot;
}

// Допоміжна функція для виведення дерева в префіксному порядку
void print_tree(TreeNode* root) 
{
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    // Створення дерева для тестування
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Оригінальне дерево: ";
    print_tree(root);
    std::cout << std::endl;

    // Створення дерева-дзеркала
    TreeNode* mirror= create_mirror(root);

    std::cout << "Дерево після обертання: ";
    print_tree(mirror);
    std::cout << std::endl;

    return 0;
}
