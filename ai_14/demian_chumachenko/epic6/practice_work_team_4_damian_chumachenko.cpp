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

    Node* flipAndCopy(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(node->data);
        newNode->left = flipAndCopy(node->right);
        newNode->right = flipAndCopy(node->left);

        return newNode;
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

    BinaryTree flipTree() {
        BinaryTree newTree;
        newTree.root = flipAndCopy(root);
        return newTree;
    }
};

int main() {
    BinaryTree<int> myTree;
    BinaryTree<int> myTree2;

    myTree.insert(15);
    myTree.insert(10);
    myTree.insert(8);
    myTree.insert(55);
    myTree.insert(30);
    myTree.insert(3);
    myTree.insert(1);

    myTree2 = myTree.flipTree();
    
    myTree.print();
    myTree2.print();

    return 0;
}