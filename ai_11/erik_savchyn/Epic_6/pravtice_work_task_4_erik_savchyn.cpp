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

// Функція для віддзеркалення дерева
TreeNode *create_mirror_flip(TreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    // Створюємо новий вузол з обернутими лівою і правою вітками
    TreeNode *newNode = new TreeNode(root->value);
    newNode->left = create_mirror_flip(root->right);
    newNode->right = create_mirror_flip(root->left);

    return newNode;
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

    TreeNode *mirrorRoot = create_mirror_flip(root);

    cout << "\nMirror Flipped Tree (Tree View):" << endl;
    printTree(mirrorRoot);

    return 0;
}
