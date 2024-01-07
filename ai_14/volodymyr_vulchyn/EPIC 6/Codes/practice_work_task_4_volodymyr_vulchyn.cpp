#include <iostream>

using namespace std;

// Структура для представлення вузла бінарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для віддзеркалення бінарного дерева
TreeNode* create_mirror_flip(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створюємо новий вузол і копіюємо дані
    TreeNode* mirroredRoot = new TreeNode(root->data);

    // Рекурсивно віддзеркалюємо ліву та праву частини дерева
    mirroredRoot->left = create_mirror_flip(root->right);
    mirroredRoot->right = create_mirror_flip(root->left);

    return mirroredRoot;
}

// Допоміжна функція для виведення бінарного дерева (в порядку "корінь-ліво-право")
void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

int main() {
    // Приклад створення бінарного дерева
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(5);

    cout << "Оригінальне дерево: ";
    printTree(root);
    cout << endl;

    // Віддзеркалюємо дерево і виводимо його
    TreeNode* mirroredRoot = create_mirror_flip(root);
    cout << "Віддзеркалене дерево: ";
    printTree(mirroredRoot);
    cout << endl;

    return 0;
}
