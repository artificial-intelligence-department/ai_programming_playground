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

    bool search(Node* node, T value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        }

        if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    int size(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + size(node->left) + size(node->right);
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

    bool search(T value) {
        return search(root, value);
    }

    int size() {
        return size(root);
    }
};

int main() {
    BinaryTree<int> myTree;
    int Q, K;
    string input;

    cin >> Q;
    cout << endl;

    for(int i = 0; i < Q; i++){
        cin >> input;
        if(input == "insert"){
            cin >> K;
            myTree.insert(K);
        }
        else if(input == "print"){
            myTree.print();
        }
        else if(input == "contains"){
            cin >> K;
            if(myTree.search(K)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(input == "size"){
            cout << myTree.size() << endl;
        }
    }

    return 0;
}