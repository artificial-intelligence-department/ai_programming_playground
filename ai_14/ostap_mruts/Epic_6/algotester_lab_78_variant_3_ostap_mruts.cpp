#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

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

    bool containsRecursive(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        }

        if (value < current->data) {
            return containsRecursive(current->left, value);
        } else {
            return containsRecursive(current->right, value);
        }
    }

    int calculateSize(Node* current) {
        if (current == nullptr) {
            return 0;
        }
        return 1 + calculateSize(current->left) + calculateSize(current->right);
    }

    void printTree(Node* current) {
        if (current == nullptr) {
            return;
        }

        printTree(current->left);
        cout << current->data << " ";
        printTree(current->right);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool contains(int value) {
        return containsRecursive(root, value);
    }

    int size() {
        return calculateSize(root);
    }

    void print() {
        printTree(root);
        cout << endl;
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree bst;

    for (int i = 0; i < Q; ++i) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (operation == "contains") {
            int value;
            cin >> value;
            if (bst.contains(value)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (operation == "size") {
            cout << bst.size() << endl;
        } else if (operation == "print") {
            bst.print();
        }
    }

    return 0;
}
