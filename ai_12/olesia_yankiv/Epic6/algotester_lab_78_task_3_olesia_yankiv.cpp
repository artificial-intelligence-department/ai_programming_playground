#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    Node* insertValue(Node* node, const T& value) {
        if (node == nullptr) {
            ++size;
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertValue(node->left, value);
        } else if (value > node->data) {
            node->right = insertValue(node->right, value);
        }

        return node;
    }

    bool containsValue(Node* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return containsValue(node->left, value);
        } else {
            return containsValue(node->right, value);
        }
    }

    void printTree(Node* node) const {
        if (node != nullptr) {
            printTree(node->left);
            std::cout << node->data << " ";
            printTree(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr), size(0) {}

    void insert(const T& value) {
        root = insertValue(root, value);
    }

    bool contains(const T& value) const {
        return containsValue(root, value);
    }

    int getSize() const {
        return size;
    }

    void print() const {
        printTree(root);
    }
};

int main() {
    int Q;
    std::cin >> Q;

    BinarySearchTree<int> tree;

    while (Q--) {
        std::string command;
        std::cin >> command;

        if (command == "insert") {
            int value;
            std::cin >> value;
            tree.insert(value);
        } else if (command == "contains") {
            int value;
            std::cin >> value;
            if (tree.contains(value)) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else if (command == "size") {
            std::cout << tree.getSize() << "\n";
        } else if (command == "print") {
            tree.print();
            std::cout << "\n";
        }
    }

    return 0;
}

