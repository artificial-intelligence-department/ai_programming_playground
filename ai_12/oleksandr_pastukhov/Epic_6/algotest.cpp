#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    void insert(Node*& current, int value);
    bool contains(Node* current, int value) const;

    int size(Node* current) const;

    void print(Node* current) const;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value);
    bool contains(int value) const;
    int size() const;
    void print() const;
};


void BinarySearchTree::insert(Node*& current, int value) {
    if (current == nullptr) {
        current = new Node(value);
    } else if (value < current->value) {
        insert(current->left, value);
    } else if (value > current->value) {
        insert(current->right, value);
    }
}

void BinarySearchTree::insert(int value) {
    insert(root, value);
}

bool BinarySearchTree::contains(Node* current, int value) const {
    if (current == nullptr) {
        return false;
    }

    if (value == current->value) {
        return true;
    } else if (value < current->value) {
        return contains(current->left, value);
    } else {
        return contains(current->right, value);
    }
}

bool BinarySearchTree::contains(int value) const {
    return contains(root, value);
}

int BinarySearchTree::size(Node* current) const {
    if (current == nullptr) {
        return 0;
    }

    return 1 + size(current->left) + size(current->right);
}

int BinarySearchTree::size() const {
    return size(root);
}

void BinarySearchTree::print(Node* current) const {
    if (current != nullptr) {
        print(current->left);
        std::cout << current->value << " ";
        print(current->right);
    }
}

void BinarySearchTree::print() const {
    print(root);
    std::cout << std::endl;
}


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
        }
    }

    return 0;
}