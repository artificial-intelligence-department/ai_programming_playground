#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

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

    void display() {
        displayRecursive(root);
    }

    void displayRecursive(Node* current) {
        if (current != nullptr) {
            displayRecursive(current->left);
            cout << current->data << " ";
            displayRecursive(current->right);
        }
    }

    Node* create_mirror_flip(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* mirrored = new Node(node->data);
        mirrored->left = create_mirror_flip(node->right);
        mirrored->right = create_mirror_flip(node->left);

        return mirrored;
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BinaryTree tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);

    cout << "Дерево: ";
    tree.display();
    cout << endl;

    Node* mirroredRoot = tree.create_mirror_flip(tree.getRoot());

    cout << "Відзеркалення дерева: ";
    BinaryTree mirroredTree;
    mirroredTree.displayRecursive(mirroredRoot);
    cout << endl;

    return 0;
}
