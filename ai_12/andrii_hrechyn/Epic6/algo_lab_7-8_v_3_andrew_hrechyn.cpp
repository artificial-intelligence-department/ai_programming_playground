#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool contains(Node* node, int value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    int size(Node* node) const {
        if (node == nullptr) {
            return 0;
        }

        return 1 + size(node->left) + size(node->right);
    }

    void print(Node* node) const {
        if (node != nullptr) {
            print(node->left);
            cout << node->value << " ";
            print(node->right);
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

    void print() const {
        print(root);
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
            cout << endl;
        }
    }

    return 0;
}
