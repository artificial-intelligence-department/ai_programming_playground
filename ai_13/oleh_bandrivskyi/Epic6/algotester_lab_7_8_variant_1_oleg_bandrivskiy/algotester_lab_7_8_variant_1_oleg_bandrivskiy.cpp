#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
    Node<T>* root;

    Node<T>* insertRecursive(Node<T>* root, T value) {
        if (root == nullptr) {
            return new Node<T>(value);
        }

        if (value < root->value) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->value) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    bool containsRecursive(Node<T>* root, T value) const {
        if (root == nullptr) {
            return false;
        }

        if (value == root->value) {
            return true;
        } else if (value < root->value) {
            return containsRecursive(root->left, value);
        } else {
            return containsRecursive(root->right, value);
        }
    }

    int sizeRecursive(Node<T>* root) const {
        if (root == nullptr) {
            return 0;
        }

        return 1 + sizeRecursive(root->left) + sizeRecursive(root->right);
    }

    void printRecursive(Node<T>* root, stringstream& output) const {
        if (root != nullptr) {
            printRecursive(root->left, output);
            output << root->value << " ";
            printRecursive(root->right, output);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(T value) {
        root = insertRecursive(root, value);
    }

    bool contains(T value) const {
        return containsRecursive(root, value);
    }

    int size() const {
        return sizeRecursive(root);
    }

    string print() const {
        stringstream output;
        printRecursive(root, output);
        return output.str();
    }
};

int main() {
    int Q;
    cin >> Q;

    BinarySearchTree<int> bst;

    stringstream output;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (query == "contains") {
            int value;
            cin >> value;
            output << (bst.contains(value) ? "Yes" : "No") << endl;
        } else if (query == "size") {
            output << bst.size() << endl;
        } else if (query == "print") {
            output << bst.print() << endl;
        }
    }

    cout << output.str();

    return 0;
}
