#include <iostream>
using namespace std;

using namespace std;

// Визначення структури для вузла дерева
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Клас "Двійкове дерево пошуку"
class BinarySearchTree {
private:
    Node* root;

    // Вставка елемента у дерево
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Пошук елемента у дереві
    bool contains(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    // Розмір дерева (кількість елементів)
    int size(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + size(node->left) + size(node->right);
    }

    // Вивід елементів дерева (рекурсивно)
    void print(Node* node) {
        if (node != nullptr) {
            print(node->left);
            cout << node->data << " ";
            print(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Метод для вставки елемента у дерево
    void insert(int value) {
        root = insert(root, value);
    }

    // Метод для перевірки наявності елемента у дереві
    bool contains(int value) {
        return contains(root, value);
    }

    // Метод для отримання розміру дерева
    int size() {
        return size(root);
    }

    // Метод для виводу елементів дерева
    void print() {
        print(root);
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree bst;

    for (int i = 0; i < Q; ++i) {
        string query;
        cin >> query;

        if (query == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (query == "contains") {
            int value;
            cin >> value;
            cout << (bst.contains(value) ? "Yes" : "No") << endl;
        } else if (query == "size") {
            cout << bst.size() << endl;
        } else if (query == "print") {
            bst.print();
        }
    }

    return 0;
}
