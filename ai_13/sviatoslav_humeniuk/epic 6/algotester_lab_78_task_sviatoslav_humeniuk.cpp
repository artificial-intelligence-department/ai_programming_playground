// Двійкове дерево пошуку
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left; // Вказівники на лівий та правий дочірні вузли
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node  ->  value) {
            node -> left = insert(node -> left, value);
        } else if (value > node -> value) {
            node -> right = insert(node -> right, value);
        }

        return node;
    }

    bool contains(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node -> value) {
            return true;
        } else if (value < node -> value) {
            return contains(node -> left, value);
        } else {
            return contains(node -> right, value);
        }
    }

    int size(Node* node) const {
        if (node == nullptr) {
            return 0;
        }

        return 1 + size(node -> left) + size(node -> right);
    }

    void print(Node* node, ostream& os) const {
        if (node != nullptr) {
            print(node -> left, os);
            os << node -> value << " ";
            print(node -> right, os);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) const {
        return contains(root, value);
    }

    int size() const {
        return size(root);
    }

    friend ostream& operator << (ostream& os, const BinarySearchTree& tree) { // Використовуємо friend, щоб мати право звертатися до приватних членів
        tree.print(tree.root, os);
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree bst;

    for (int i = 0; i < Q; ++i) { // Цикл для обробки запитів
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (operation == "contains") {
            int value;
            cin >> value;
            cout << (bst.contains(value) ? "Yes" : "No") << endl;
        } else if (operation == "size") {
            cout << bst.size() << endl;
        } else if (operation == "print") {
            cout << bst << endl;
        }
    }

    return 0;
}