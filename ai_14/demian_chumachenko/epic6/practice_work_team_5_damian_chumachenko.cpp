#include <iostream>
#include <string>

using namespace std;

template <typename T>
class BinaryTree{
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, T value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void print(Node* node) {
        if (node != nullptr) {
            print(node->left);
            cout << node->data << " ";
            print(node->right);
        }
    }

    void tree_sum(Node* node) {
        if (node == nullptr) {
            return;
        }

        // First recur for left and right subtrees
        tree_sum(node->left);
        tree_sum(node->right);

        // Update the value of this node as the sum of its children
        if (node->left != nullptr) {
            node->data = node->left->data;
        }
        if (node->right != nullptr) {
            node->data += node->right->data;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    void print() {
        print(root);
        cout << endl;
    }

    void tree_sum() {
        tree_sum(root);
    }
};

int main() {
    BinaryTree<int> myTree;

    myTree.insert(15);
    myTree.insert(10);
    myTree.insert(8);
    myTree.insert(55);
    myTree.insert(30);

    myTree.print();

    myTree.tree_sum();

    cout << endl;

    myTree.print();

    return 0;
}