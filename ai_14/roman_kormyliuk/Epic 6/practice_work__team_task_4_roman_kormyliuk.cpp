#include <iostream>
using namespace std;
// Структура для представлення вузла бінарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функція для створення віддзеркаленого дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    // Базовий випадок: якщо дерево пусте, повертаємо nullptr
    if (root == nullptr) {
        return nullptr;
    }

    // Створюємо новий вузол зі значенням поточного вузла
    TreeNode* new_root = new TreeNode(root->data);

    // Рекурсивно віддзеркалюємо праве та ліве піддерева
    new_root->left = create_mirror_flip(root->right);
    new_root->right = create_mirror_flip(root->left);

    return new_root;
}

// Функція для виведення дерева у вигляді "ін-ордер" (ліве - корінь - праве)
void in_order_traversal(TreeNode* root) {
    if (root != nullptr) {
        in_order_traversal(root->left);
        cout << root->data << " ";
        in_order_traversal(root->right);
    }
}

// Функція для видалення вузлів бінарного дерева (використовується для звільнення пам'яті)
void delete_tree(TreeNode* root) {
    if (root != nullptr) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

int main() {
    // Створюємо приклад бінарного дерева
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Виводимо оригінальне дерево
    cout << "Original tree (in-order traversal): ";
    in_order_traversal(root);
    cout << endl;

    // Створюємо та виводимо віддзеркалене дерево
    TreeNode* mirrored_tree = create_mirror_flip(root);
    cout << "Mirrored tree (in-order traversal): ";
    in_order_traversal(mirrored_tree);
    cout << endl;

    // Звільняємо пам'ять
    delete_tree(root);
    delete_tree(mirrored_tree);

    return 0;
}