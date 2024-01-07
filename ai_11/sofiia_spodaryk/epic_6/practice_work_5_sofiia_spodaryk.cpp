#include <iostream>
#include <queue>
using namespace std;

// Структура для представлення вузла бінарного дерева
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

// Функція для обчислення та запису суми підвузлів для кожного батьківського вузла
void tree_sum(TreeNode* root) {
    // Базовий випадок: якщо корінь порожній, повертаємо
    if (root == nullptr) {
        return;
    }

    // Використання обходу у ширину для ітеративного обходу дерева
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int sum = 0;

        // Обчислення суми підвузлів та їх додавання до черги для обробки
        if (current->left) {
            sum += current->left->data;
            q.push(current->left);
        }
        if (current->right) {
            sum += current->right->data;
            q.push(current->right);
        }

        // Запис суми до поточного вузла (якщо він має хоча б одного нащадка)
        if (current->left || current->right) {
            current->data = sum;
        }
    }
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

    // Обчислення та запис суми підвузлів для кожного батьківського вузла
    tree_sum(root);

    // Виведення дерева після запису сум
    cout << "Tree after sum calculation: ";
    print_T(root);
    cout << endl;

    // Звільнення виділеної пам'яті для вихідного дерева
    delete root;

    return 0;
}