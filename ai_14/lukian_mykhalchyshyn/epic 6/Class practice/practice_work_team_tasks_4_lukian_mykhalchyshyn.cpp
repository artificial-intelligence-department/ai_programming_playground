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

void printNodes(TreeNode* root)  // Функція для виведення інформації про вузол та його дочірні вузли
{
    if (root == nullptr) 
    {
        return;
    }

    cout << "Node " << root->data << ":\n";

    if (root->left) 
    {
        cout << "  Node " << root->left->data << " (Left child): " << "\n";
    }

    if (root->right) 
    {
        cout << "  Node " << root->right->data << " (Right child): " << "\n";
    }
}

void deleteSubtree(TreeNode* root) // Функція для видалення піддерева 
{
    if (root == nullptr) 
    {
        return;
    }

    deleteSubtree(root->left);// Рекурсивно звільнюємо пам'ять для всіх вузлів дерева
    deleteSubtree(root->right);

    delete root; // Звільнюємо пам'ять для поточного вузла
}

TreeNode* copySubtree(TreeNode* root) // Функція для копіювання піддерева
{
    if (root == nullptr) 
    {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->data); // Створюємо новий вузол з таким самим значенням

    newRoot->left = copySubtree(root->left); // Рекурсивно копіюємо ліву та праву вітки
    newRoot->right = copySubtree(root->right);

    return newRoot;
}

TreeNode* create_mirror_tree(TreeNode* root) // Функція для створення дзеркального відображення дерева
{
    if (root == nullptr) 
    {
        return nullptr;
    }

    TreeNode* newRoot = new TreeNode(root->data);  // Створюємо новий вузол з таким самим значенням

    newRoot->right = create_mirror_tree(root->left); // Рекурсивно створюємо дзеркальні вітки (праву і ліву)
    newRoot->left = create_mirror_tree(root->right);

    return newRoot;
}

int main() 
{
    // Створюємо оригінальне дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Оригінальне дерево:\n";
    printNodes(root);

    TreeNode* mirroredRoot = create_mirror_tree(root);  // Створюємо дзеркальне відображення дерева

    cout << "Дзеркальне відображення дерева:\n"; // Виводимо дзеркальне відображення дерева
    printNodes(mirroredRoot);

    deleteSubtree(root); // Звільнюємо пам'ять оригінального дерева та його дзеркального відображення
    deleteSubtree(mirroredRoot);

    return 0;
}
