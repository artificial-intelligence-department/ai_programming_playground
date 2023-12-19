#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class BinaryTree {
private:
    node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    node* insertRecursive(node* current, int value) {
        if (current == nullptr) {
            node* newnode = new node;
            newnode ->data = value;
            return newnode;
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

    void displayRecursive(node* current) {
        if (current != nullptr) {
            displayRecursive(current->left);
            cout << current->data << " ";
            displayRecursive(current->right);
        }
    }

    node* create_mirror_flip(node* Node) {
        if (Node == nullptr) {
            return nullptr;
        }

        node* mirrored = new node;
        mirrored->data = Node->data; // Assign the data value

        mirrored->left = create_mirror_flip(Node->right);
        mirrored->right = create_mirror_flip(Node->left);

        return mirrored;
    }


    node* getRoot() {
        return root;
    }
};

int main() {
    BinaryTree tree;

    tree.insert(7);
    tree.insert(8);
    tree.insert(11);
    tree.insert(2);
    tree.insert(0);
    tree.insert(54);
    tree.insert(3);
    tree.insert(1);
    tree.insert(23);

    cout << "Дерево: ";
    tree.display();
    cout << endl;
    BinaryTree mirroredTree;
    node* mirroredRoot = tree.create_mirror_flip(tree.getRoot());

    cout << "Відзеркалення дерева: ";

    mirroredTree.displayRecursive(mirroredRoot);
    cout << endl;

    return 0;
}
