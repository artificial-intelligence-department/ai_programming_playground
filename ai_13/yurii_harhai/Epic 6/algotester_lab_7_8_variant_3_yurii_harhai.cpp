#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

class BinaryTree {
    Node* root;
    int size;

public:
    BinaryTree() : root(nullptr), size(0) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) {
        return contains(root, value);
    }

    void print() {
        print(root);
        cout << endl;
    }

    int getSize() {
        return size;
    }

private:
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            node = new Node{value, nullptr, nullptr};
            size++;
        } else if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool contains(Node* node, int value) {
        if (node == nullptr) {
            return false;
        } else if (value < node->value) {
            return contains(node->left, value);
        } else if (value > node->value) {
            return contains(node->right, value);
        } else {
            return true;
        }
    }

    void print(Node* node) {
        if (node != nullptr) {
            print(node->left);
            cout << node->value << ' ';
            print(node->right);
        }
    }
};

int main() {
    BinaryTree tree;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        if (command == "insert") {
            int value;
            cin >> value;
            if (!tree.contains(value)) {
                tree.insert(value);
            }
        } else if (command == "contains") {
            int value;
            cin >> value;
            cout << (tree.contains(value) ? "Yes" : "No") << endl;
        } else if (command == "size") {
            cout << tree.getSize() << endl;
        } else if (command == "print") {
            tree.print();
        }
    }
    return 0;
}
