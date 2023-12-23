#include <iostream>
using namespace std;

// Визначення структури вузла дерева
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Конструктор для створення вузла зі значенням x
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //отримує значення для вузла і встановлює вказівники на ліве та праве піддерево як nullptr
};

// Функція для створення віддзеркаленого дерева 
TreeNode *create_mirror_flip(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створення нового вузла зі значенням вузла root, але з обміняними лівим і правим піддеревами
    TreeNode *mirror = new TreeNode(root->val); // Створення нового вузла зі значенням вузла root, 
    //minor - вказівник на наш елемент
    mirror->right = create_mirror_flip(root->left); // Рекурсивно викликає саму себе для лівого піддерева root, присвоюючи його правому піддереву новий вузол
    mirror->left = create_mirror_flip(root->right); // Рекурсивно викликає саму себе для правого піддерева root, присвоюючи його лівому піддереву новий вузол

    // Повертає віддзеркалене піддерево
    return mirror;
}

// Функція для обходу дерева в порядку "впорядкованого виводу"
void inorderTraversal(TreeNode *root) {
    if (root != nullptr) {
        inorderTraversal(root->left); // Рекурсивний виклик для лівого піддерева
        cout << root->val << " "; // Вивід значення поточного вузла
        inorderTraversal(root->right); // Рекурсивний виклик для правого піддерева
    }
}

int main() {
    // Приклад вхідного дерева
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->left->right = new TreeNode(2);

    cout << "Original tree: ";
    inorderTraversal(root); // Вивід вхідного дерева у порядку "впорядкованого виводу"
    cout << endl;

    // Створення віддзеркаленого дерева без модифікації вхідного дерева
    TreeNode *mirrorTree = create_mirror_flip(root);

    cout << "Changed tree: ";
    inorderTraversal(mirrorTree); // Вивід віддзеркаленого дерева у порядку "впорядкованого виводу"
    cout << endl;

    return 0;
}
