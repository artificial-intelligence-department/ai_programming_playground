#include <iostream>
using namespace std;

template <typename T>
class Tree {
private:
    struct Node {
        T data;
        Node* right;
        Node* left;
    };
    Node* root;

    bool insertNode(Node*& current, const T& value) {
        if (current == nullptr) {
            current = new Node{value};
            return true;
        } else if (value < current->data) {
            return insertNode(current->left, value);
        } else if (value > current->data) {
            return insertNode(current->right, value);
        } else {
            return false;
        }
    }

    bool containsNode(const Node* current, const T& value) const {
        if (current == nullptr) {
            return false;
        } else if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return containsNode(current->left, value);
        } else {
            return containsNode(current->right, value);
        }
    }

    size_t sizeNode(const Node* node) const {
        return node == nullptr ? 0 : sizeNode(node->left) + 1 + sizeNode(node->right);
    }

    void printNode(const Node* node) const {
        if (node != nullptr) {
            printNode(node->left);
            cout << node->data << " ";
            printNode(node->right);
        }
    }

    void printNode(const Node* node, ostream& os) const {
        if (node != nullptr) {
            printNode(node->left, os);
            os << node->data << " ";
            printNode(node->right, os);
        }
    }

public:
    Tree()
            : root(nullptr) {}

    bool insert(const T& value) {
        return insertNode(root, value);
    }

    [[nodiscard]] bool contains(const T& value) const {
        return containsNode(root, value);
    }

    [[nodiscard]] size_t size() const {
        return sizeNode(root);
    }

    void print() const {
        printNode(root);
        cout << endl;
    }

    friend ostream& operator<<(ostream& os, const Tree& tree) {
        tree.printNode(tree.root, os);
        return os;
    }
};
int main() {
    Tree<int> tree;
    int q, v;
    cin >> q;
    string s;
    cout << endl;
    for(int i = 0; i < q; i++){
        cin >> s;
        if(s == "insert"){
            cin >> v;
            tree.insert(v);
        }
        else if(s == "print"){
            cout << tree << endl;
        }
        else if(s == "contains"){
            cin >> v;
            tree.contains(v) ? cout << "Yes\n" : cout << "No\n";
        }
        else if(s == "size"){
            cout << tree.size() << endl;
        }
    }
    return 0;
}