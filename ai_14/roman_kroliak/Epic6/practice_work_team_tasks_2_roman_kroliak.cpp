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

    void mirrorNode(Node* node) {
        if (node == nullptr) {
            return;
        }
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        mirrorNode(node->left);
        mirrorNode(node->right);
    }

    static void copyNode(Node*& node1, Node* const& node2){
        if (node2 == nullptr){
            return;
        }
        node1 = new Node{node2->data};
        copyNode(node1->left, node2->left);
        copyNode(node1->right, node2->right);
    }

    Tree create_mirrored_tree(Node* node){
        Tree mirrored;
        copyNode(mirrored.root, node);
        mirrorNode(mirrored.root);
        return mirrored;
    }

    int tree_sum(Node* node){
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) return node->data;
        return node->data = tree_sum(node->left) + tree_sum(node->right);
    };

public:
    Tree()
            : root(nullptr) {}

    Tree(const Tree& other)
            : root(nullptr) {
        copyNode(this->root, other.root);
    }

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

    Tree mirror() {
        return create_mirrored_tree(root);
    }

    void sum() {
        tree_sum(root);
    }

    friend ostream& operator<<(ostream& os, const Tree& tree) {
        tree.printNode(tree.root, os);
        return os;
    }
};

int main() {
    Tree<int> tree;
    int a[10] = {5,6,3,7,8,9,4,2,5,1};
    for (int i : a)
        tree.insert(i);
    cout << tree << endl;
    cout << tree.mirror() << endl;
    cout << tree << endl;
    tree.sum();
    cout << tree;
    return 0;
}
