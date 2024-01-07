#include <iostream>
using namespace std;

// Визначення структури для вузла бінарного дерева
struct TreeNode {
    int data;         // Значення вузла
    TreeNode* left;   // Вказівник на лівого дочірнього вузла
    TreeNode* right;  // Вказівник на правого дочірнього вузла

    // Конструктор для створення нового вузла з заданим значенням
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Функція для створення дзеркального відображення бінарного дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    // Базовий випадок: якщо корінь порожній, повертаємо nullptr
    if (root == nullptr) {
        return nullptr;
    }

    // Створення нового вузла зі значенням кореня поточного піддерева
    TreeNode* mirrored_node = new TreeNode(root->data);

    // Рекурсивний виклик для лівого та правого піддерев
    // Замінюємо лівого дочірнього на дзеркальне відображення правого піддерева,
    // а правого дочірнього - на дзеркальне відображення лівого піддерева
    mirrored_node->left = create_mirror_flip(root->right);
    mirrored_node->right = create_mirror_flip(root->left);

    // Повертаємо вузол дзеркально відображеного дерева
    return mirrored_node;
}

// Функція для виведення значень вузлів дерева в порядку "лівий-корінь-правий"
void print_T(TreeNode* root) {
    if (root != nullptr) {
        // Рекурсивний виклик для лівого піддерева
        print_T(root->left);

        // Виведення значення поточного вузла
        cout << root->data << " ";

        // Рекурсивний виклик для правого піддерева
        print_T(root->right);
    }
}

// Основна функція програми
int main() {
    // Створення бінарного дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Виведення вихідного дерева
    cout << "Original tree: ";
    print_T(root);
    cout << endl;

    // Віддзеркалення дерева
    TreeNode* mirrored_root = create_mirror_flip(root);

    // Виведення дзеркально відображеного дерева
    cout << "Mirrored tree: ";
    print_T(mirrored_root);
    cout << endl;

    // Звільнення виділеної пам'яті для вихідного та дзеркально відображеного дерев
    delete root;
    delete mirrored_root;

    return 0;
}