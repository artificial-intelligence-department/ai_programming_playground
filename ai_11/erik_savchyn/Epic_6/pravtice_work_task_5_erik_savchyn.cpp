#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

// Структура для вузла бінарного дерева
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Допоміжна функція для виведення дерева у вигляді дерева
void printTree(TreeNode *root, int depth = 0) {
    const int COUNT = 5;
    if (root == nullptr)
        return;

    depth += COUNT;

    printTree(root->right, depth);

    cout << endl;
    for (int i = COUNT; i < depth; i++)
        cout << " ";
    cout << root->value;

    printTree(root->left, depth);
}

// Функція для запису суми підвузлів у батьківський вузол
void tree_sum(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        root->value += root->left->value;
    }

    if (root->right != nullptr) {
        root->value += root->right->value;
    }

    tree_sum(root->left);
    tree_sum(root->right);
}

// Функція для вставки випадкових чисел в бінарне дерево
TreeNode *insertRandom(TreeNode *root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insertRandom(root->left, value);
    } else if (value > root->value) {
        root->right = insertRandom(root->right, value);
    }

    return root;
}

int main() {
    // Генератор випадкових чисел
    random_device rd;
    mt19937 gen(rd());

    // Випадкові, неповторювані числа від 1 до 15
    vector<int> randomNumbers;
    for (int i = 1; i <= 15; ++i) {
        randomNumbers.push_back(i);
    }

    shuffle(randomNumbers.begin(), randomNumbers.end(), gen);

    TreeNode *root = nullptr;

    // Вставка випадкових чисел в бінарне дерево
    for (int number : randomNumbers) {
        root = insertRandom(root, number);
    }

    cout << "Original Tree (Tree View):" << endl;
    printTree(root);

    tree_sum(root);

    cout << "\nTree with Sum of Subtrees (Tree View):" << endl;
    printTree(root);

    return 0;
}
