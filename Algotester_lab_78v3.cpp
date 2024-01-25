#include <iostream>

class BinarySearchTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insertNode(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insertNode(node->left, value);
        } else if (value > node->data) {
            insertNode(node->right, value);
        }
    }

    bool containsValue(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return containsValue(node->left, value);
        } else {
            return containsValue(node->right, value);
        }
    }

    int calculateSize(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + calculateSize(node->left) + calculateSize(node->right);
    }

    void printTree(Node* node) const {
        if (node != nullptr) {
            printTree(node->left);
            std::cout << node->data << " ";
            printTree(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        insertNode(root, value);
    }

    bool contains(int value) const {
        return containsValue(root, value);
    }

    int size() const {
        return calculateSize(root);
    }

    void print() const {
        printTree(root);
        std::cout << std::endl;
    }
};

int main() {
    int Q;
    std::cin >> Q;

    BinarySearchTree bst;

    while (Q--) {
        std::string identifier;
        std::cin >> identifier;

        if (identifier == "insert") {
            int value;
            std::cin >> value;
            bst.insert(value);
        } else if (identifier == "contains") {
            int value;
            std::cin >> value;
            std::cout << (bst.contains(value) ? "Yes" : "No") << std::endl;
        } else if (identifier == "size") {
            std::cout << bst.size() << std::endl;
        } else if (identifier == "print") {
            bst.print();
        }
    }

    return 0;
}





