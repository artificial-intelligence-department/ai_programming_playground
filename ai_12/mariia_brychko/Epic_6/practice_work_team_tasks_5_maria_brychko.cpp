#include <iostream>
using namespace std;

// Структура вузла дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для обчислення суми підвузлів для кожного батьківського вузла
void tree_sum(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return; // Якщо вузол-листок або пустий вузол, повертаємося
    }

    tree_sum(root->left);  // Рекурсивно обходимо ліве піддерево
    tree_sum(root->right); // Рекурсивно обходимо праве піддерево

    int leftSum = (root->left != nullptr) ? root->left->data : 0;   // Сума значень лівого піддерева   ? - Це тернарний оператор, який має форму: умова ? значення_якщо_правда : значення_якщо_неправда
    int rightSum = (root->right != nullptr) ? root->right->data : 0; // Сума значень правого піддерева

    root->data += leftSum + rightSum; // Записуємо суму підвузлів у поточний вузол
}

// Функція для виведення дерева
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Приклад створення дерева
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Виведення початкового дерева (pre-order)
    cout << "Original tree: ";
    printTree(root);
    cout << endl;

    // Обчислення суми підвузлів для кожного батьківського вузла
    tree_sum(root);

    // Виведення дерева після обчислення суми підвузлів
    cout << "Tree after sum calculation: ";
    printTree(root);
    cout << endl;

    return 0;
}
