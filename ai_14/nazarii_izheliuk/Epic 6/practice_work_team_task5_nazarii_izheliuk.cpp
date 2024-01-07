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

    void updateParentNodeSums() {
        updateParentSumsRecursive(root);
    }

    int updateParentSumsRecursive(Node* current) {
        if (current == nullptr) {
            return 0;
        }

        int leftSum = updateParentSumsRecursive(current->left);
        int rightSum = updateParentSumsRecursive(current->right);

        int sum = leftSum + rightSum + current->data;

        if (current->left != nullptr || current->right != nullptr) {
            current->data = leftSum + rightSum;
        }

        return sum;
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

    cout << "Елементи бінарного дерева: ";
    tree.display();
    cout << endl;

    tree.updateParentNodeSums();

    cout << "Елементи бінарного дерева після оновлення батьківських вузлів: ";
    tree.display();
    cout << endl;

    return 0;
}
