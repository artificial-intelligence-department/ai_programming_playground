#include <iostream>
using namespace std;

// Структура, яка представляє вузол бінарного дерева пошуку (BST)
struct node {
    int key;            // Ключ вузла
    struct node* left;  // Вказівник на лівого нащадка
    struct node* right; // Вказівник на правого нащадка
};

// Функція для створення нового вузла BST з заданим ключем
struct node* newNode(int item) {
    struct node* temp = new struct node; // Створення нового вузла
    temp->key = item;                     // Ініціалізація ключа
    temp->left = temp->right = NULL;      // Встановлення лівого та правого вказівників на NULL
    return temp;
}

// Функція для вставки нового вузла з заданим ключем в BST
struct node* insert(struct node* node, int key) {
    // Якщо дерево пусте, створюємо новий вузол і повертаємо його
    if (node == NULL)
        return newNode(key);

    // Рекурсивно спускаємося вниз по дереву
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Повертаємо (не змінений) вказівник на вузол
    return node;
}

// Функція для пошуку вузла з заданим ключем в BST
struct node* search(struct node* root, int key) {
    // Базові випадки: корінь порожній або ключ присутній в корені
    if (root == NULL || root->key == key)
        return root;

    // Ключ більший за ключ кореня
    if (root->key < key)
        return search(root->right, key);

    // Ключ менший за ключ кореня
    return search(root->left, key);
}

// Головна функція
int main() {
    struct node* root = NULL;

    // Вставка елементів у BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

 
    int key;
    cin >> key; 
    if (search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;


    return 0;
}