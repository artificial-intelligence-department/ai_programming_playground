#include <iostream>

/*
insert(int value): Додає новий елемент у дерево.
contains(int value) const: Перевіряє, чи міститься задане значення в дереві.
size() const: Обчислює розмір (кількість елементів) дерева.
print() const: Виводить всі елементи дерева у відсортованому порядку.
*/

/*
Ваше завдання - власноруч реалізувати структуру даних "Двійкове дерево пошуку".
Ви отримаєте 
Q
 запитів, кожен запит буде починатися зі слова-ідентифікатора, після якого йдуть його параметри
*/

// Визначення структури для вузла дерева
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Клас для двійкового дерева пошуку
class BinarySearchTree {
private:
    Node* root;

    // Рекурсивна функція для вставки елемента в дерево
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Рекурсивна функція для перевірки наявності елемента у дереві
    bool containsRecursive(Node* current, int value) const {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return containsRecursive(current->left, value);
        } else {
            return containsRecursive(current->right, value);
        }
    }

    // Рекурсивна функція для обчислення розміру дерева
    int sizeRecursive(Node* current) const {
        return (current == nullptr) ? 0 : (1 + sizeRecursive(current->left) + sizeRecursive(current->right));
    }

    // Рекурсивна функція для виведення елементів дерева
    void printRecursive(Node* current) const {
        if (current != nullptr) {
            printRecursive(current->left);
            std::cout << current->data << " ";
            printRecursive(current->right);
        }
    }

public:
    // Конструктор
    BinarySearchTree() : root(nullptr) {}

    // Функція для вставки елемента в дерево
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Функція для перевірки наявності елемента у дереві
    bool contains(int value) const {
        return containsRecursive(root, value);
    }

    // Функція для обчислення розміру дерева
    int size() const {
        return sizeRecursive(root);
    }

    // Функція для виведення елементів дерева
    void print() const {
        printRecursive(root);
    }
};

int main() {
    int Q;
    std::cin >> Q;

    BinarySearchTree bst;

    while (Q--) {
        std::string operation;
        std::cin >> operation;

        if (operation == "insert") {
            int value;
            std::cin >> value;
            bst.insert(value);
        } else if (operation == "contains") {
            int value;
            std::cin >> value;
            std::cout << (bst.contains(value) ? "Yes" : "No") << std::endl;
        } else if (operation == "size") {
            std::cout << bst.size() << std::endl;
        } else if (operation == "print") {
            bst.print();
            std::cout << std::endl;
        }
    }

    return 0;
}
