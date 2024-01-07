#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
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
            return new node(value);
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

    void updateParentNodeSums() {
        updateParentSumsRecursive(root);
    }

    int updateParentSumsRecursive(node* current) {
        if (current == nullptr) {
            return 0;
        }

        int leftSum = updateParentSumsRecursive(current->left);
        int rightSum = updateParentSumsRecursive(current->right);

        int sum = leftSum + rightSum + current->data;

        if (current->left != nullptr || current->right != nullptr) {
            current->data += leftSum + rightSum;
        }

        return sum;
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

    cout << "Elements of the binary tree in order: ";
    tree.display();
    cout << endl;

    tree.updateParentNodeSums();

    cout << "Elements of the binary tree after updating parent nodes with sums: ";
    tree.display();
    cout << endl;

    return 0;
}
