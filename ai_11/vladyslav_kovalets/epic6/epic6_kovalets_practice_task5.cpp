#include <iostream>
#include <queue>

struct TreeNode 
{
    int data;         // Значення вузла
    TreeNode* left;    // Вказівник на ліву вітку
    TreeNode* right;   // Вказівник на праву вітку

    // Конструктор для ініціалізації вузла з заданим значенням та вказівниками на ліву та праву вітки
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функція для ітеративного обчислення сум значень підвузлів та запису їх у батьківський вузол
void tree_sum(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    std::queue<TreeNode*> levelOrderQueue;
    levelOrderQueue.push(root);

    while (!levelOrderQueue.empty()) 
    {
        TreeNode* current = levelOrderQueue.front();
        levelOrderQueue.pop();

        // Обчислення суми значень підвузлів 
        int sum = 0;
        if (current->left != nullptr) 
        {
            sum += current->left->data;
            levelOrderQueue.push(current->left);
        }
        if (current->right != nullptr) 
        {
            sum += current->right->data;
            levelOrderQueue.push(current->right);
        }
        // Запис суми у дерево
        if (current->left != nullptr || current->right != nullptr) 
        {
            current->data = sum;
        }
    }
}

// Допоміжна функція для виведення дерева в префіксному порядку
void print_tree(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    std::cout << root->data << " ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() 
{
    // Створення дерева для тестування
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Оригінальне дерево: ";
    print_tree(root);
    std::cout << std::endl;

    // Виклик функції для обчислення сум та зміни значень вузлів
    tree_sum(root);

    std::cout << "Дерево після змін: ";
    print_tree(root);
    std::cout << std::endl;

    return 0;
}
