#include <iostream>
#include <string>
using namespace std;

template <typename T>
class BinTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insertRec(Node* root, T value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    bool searchRec(Node* root, T value) {
        if (root == nullptr) {
            return false;
        }

        if (root->data == value) {
            return true;
        }

        if (value < root->data) {
            return searchRec(root->left, value);
        } else {
            return searchRec(root->right, value);
        }
    }

    int sizeRec(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + sizeRec(root->left) + sizeRec(root->right);
    }

    void printRec(Node* root) {
        if (root == nullptr) {
            return;
        }

        printRec(root->left);
        cout << root->data << " ";
        printRec(root->right);
    }

public:
    BinTree() : root(nullptr) {}

    void insert(T value) {
        root = insertRec(root, value);
    }

    bool contains(T value) {
        return searchRec(root, value);
    }

    int getSize() {
        return sizeRec(root);
    }

    void print() {
        printRec(root);
        cout << "\n";
    }

    friend ostream& operator<<(ostream& os, BinTree& tree) {
        tree.print();
        return os;
    }
};

int main() {
    int Q, value;
    cin >> Q;

    BinTree<int> tree;
    
    for(int i=0; i<Q; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
        
            cin >> value;
            tree.insert(value);

        } else if (command == "contains") {
        
            cin >> value;

            if(tree.contains(value)){
                cout<<"Yes\n";
            } else {
                cout<<"No\n";
            }

        } else if (command == "size") {

            cout << tree.getSize() << "\n";

        } else if (command == "print") {
            
            cout << tree;
        }
    }

    return 0;
}

