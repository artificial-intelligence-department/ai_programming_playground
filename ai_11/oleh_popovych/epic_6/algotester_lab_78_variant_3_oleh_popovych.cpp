//
// Created by olehio-p on 12/7/2023.
//
#include <iostream>

class BinarySearchTree {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;

            explicit Node(int value) {
                data = value;
                left = nullptr;
                right = nullptr;
            }
        };

        Node* root;

        Node* insert0(Node* current, int value) {
            if (!current) {
                return new Node(value);
            }

            if (value < current->data) {
                current->left = insert0(current->left, value);
            } else if (value > current->data) {
                current->right = insert0(current->right, value);
            }

            return current;
        }

        bool contains0(Node* current, int value) const {
            if (!current) {
                return false;
            }

            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                return contains0(current->left, value);
            } else {
                return contains0(current->right, value);
            }
        }

        int size0(Node* current) const {
            if (!current) {
                return 0;
            }

            return 1 + size0(current->left) + size0(current->right);
        }

        void print0(Node* current) const {
            if (current) {
                print0(current->left);
                std::cout << current->data << " ";
                print0(current->right);
            }
        }

    public:
        BinarySearchTree() {
            root = nullptr;
        }

        void insert(int value) {
            root = insert0(root, value);
        }

        bool contains(int value) {
            return contains0(root, value);
        }

        int size() {
            return size0(root);
        }

        void print() {
            print0(root);
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