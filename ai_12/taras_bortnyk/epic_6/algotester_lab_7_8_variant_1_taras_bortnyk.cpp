#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    bool containsRecursive(Node* root, int value) {
        if (root == nullptr) {
            return false;
        }

        if (root->data == value) {
            return true;
        } else if (value < root->data) {
            return containsRecursive(root->left, value);
        } else {
            return containsRecursive(root->right, value);
        }
    }

    int sizeRecursive(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
    }

    void printRecursive(Node* root) {
        if (root != nullptr) {
            printRecursive(root->left);
            std::cout << root->data << " ";
            printRecursive(root->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool contains(int value) {
        return containsRecursive(root, value);
    }

    int size() {
        return sizeRecursive(root);
    }

    void print() {
        printRecursive(root);
    }
};

int main() {
    int Q;
    std::cin >> Q;

    BinarySearchTree bst;

    while (Q--) {
        std::string query;
        std::cin >> query;

        if (query == "insert") {
            int value;
            std::cin >> value;
            bst.insert(value);
        } else if (query == "contains") {
            int value;
            std::cin >> value;
            if (bst.contains(value)) {
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
        } else if (query == "size") {
            std::cout << bst.size() << std::endl;
        } else if (query == "print") {
            bst.print();
            std::cout << std::endl;
        }
    }

    return 0;
}

