#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree {
public:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& value) : value(value), left(nullptr), right(nullptr) {}
    };

    BinarySearchTree() : __root(nullptr), __size(0) {}

    void Insert(const T& value) {
        __root = InsertRecursive(__root, value);
    }

    bool Contains(const T& value) const {
        return ContainsRecursive(__root, value);
    }

    int Size() const {
        return __size;
    }

    void Print() const {
        PrintInorder(__root);
        cout << endl;
    }

private:
    Node* __root;
    int __size;

    Node* InsertRecursive(Node* root, const T& value) {
        if (root == nullptr) {
            __size++;
            return new Node(value);
        }

        if (value < root->value) {
            root->left = InsertRecursive(root->left, value);
        } else if (value > root->value) {
            root->right = InsertRecursive(root->right, value);
        }

        return root;
    }

    bool ContainsRecursive(const Node* root, const T& value) const {
        if (root == nullptr) {
            return false;
        }

        if (value == root->value) {
            return true;
        } else if (value < root->value) {
            return ContainsRecursive(root->left, value);
        } else {
            return ContainsRecursive(root->right, value);
        }
    }

    void PrintInorder(const Node* root) const {
        if (root != nullptr) {
            PrintInorder(root->left);
            cout << root->value << " ";
            PrintInorder(root->right);
        }
    }
};

int main() {
    int q;
    cin >> q;

    BinarySearchTree<int> bstree;

    for (int i = 0; i < q; ++i) {
        string operation;
        cin >> operation;

        if (operation == "insert") {
            int value;
            cin >> value;
            bstree.Insert(value);
        } else if (operation == "contains") {
            int value;
            cin >> value;
            cout << (bstree.Contains(value) ? "Yes" : "No") << endl;
        } else if (operation == "size") {
            cout << bstree.Size() << endl;
        } else if (operation == "print") {
            bstree.Print();
        }
    }

    return 0;
}
