#include <iostream>

using namespace std;

class TreeNode // Клас, що представляє вузол бінарного дерева
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {} // Конструктор для ініціалізації значень вузла
};

void print_tree(TreeNode* root) // Функція для виведення дерева
{
    if (root == nullptr) 
    {
        return;
    }

    cout << "Node " << root->data << ":\n";

    if (root->left) 
    {
        cout << "  Left child: " << root->left->data << "\n";
    }

    if (root->right) 
    {
        cout << "  Right child: " << root->right->data << "\n";
    }

    if (root->left || root->right) 
    {
        print_tree(root->left); // Якщо вузол не є листком, виводимо його дітей
        print_tree(root->right);
    }
}

void deleteSubtree(TreeNode* root) // Функція для видалення піддерева
{
    if (root == nullptr) 
    {
        return;
    }

    deleteSubtree(root->left); // Рекурсивно звільнюємо пам'ять для всіх вузлів дерева
    deleteSubtree(root->right);

    delete root; // Звільнюємо пам'ять для поточного вузла
}

void tree_sum(TreeNode* root) // Функція для запису суми підвузлів в батьківський вузол
{
    if (root == nullptr) 
    {
        return;
    }

    tree_sum(root->left); // Рекурсивно обчислюємо суми для лівого і правого піддерева
    tree_sum(root->right);

    if (root->left || root->right) // Обчислюємо суму підвузлів і записуємо її в батьківський вузол (лише якщо він не є листком)
    {
        int sum = 0;
        if (root->left) 
        {
            sum += root->left->data;
        }
        if (root->right) 
        {
            sum += root->right->data;
        }

        root->data = sum;
    }
}

int main() 
{
    // Створюємо бінарне дерево
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(6);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(17);
    root->left->right = new TreeNode(19);

    cout << "До виконання функції tree_sum:\n";
    print_tree(root);

    tree_sum(root);

    cout << "\nПісля виконання функції tree_sum:\n";
    print_tree(root);

    deleteSubtree(root);

    return 0;
}
