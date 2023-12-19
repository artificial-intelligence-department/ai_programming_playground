#include <iostream>
#include <string>

using namespace std;

class TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}

    friend class Tree;
};

class Tree {
    TreeNode* root;

    TreeNode* addNode(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode(data);
        }

        if (data < node->data) {
            node->left = addNode(node->left, data);
        } else if (data > node->data) {
            node->right = addNode(node->right, data);
        }

        return node;
    }

    bool findNode(TreeNode* node, int data) const {
        if (node == nullptr) {
            return false;
        }

        if (data == node->data) {
            return true;
        } else if (data < node->data) {
            return findNode(node->left, data);
        } else {
            return findNode(node->right, data);
        }
    }

    int countNodes(TreeNode* node) const {
        if (node == nullptr) {
            return 0;
        }

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void displayTree(TreeNode* node, ostream& os) const {
        if (node != nullptr) {
            displayTree(node->left, os);
            os << node->data << " ";
            displayTree(node->right, os);
        }
    }

public:
    Tree() : root(nullptr) {}

    void addNode(int data) {
        root = addNode(root, data);
    }

    bool findNode(int data) const {
        return findNode(root, data);
    }

    int countNodes() const {
        return countNodes(root);
    }

    friend ostream& operator<<(ostream& os, const Tree& tree) {
        tree.displayTree(tree.root, os);
        return os;
    }
};

int main() {
    int numQueries;
    cin >> numQueries;

    Tree tree;

    for (int i = 0; i < numQueries; ++i) {
        string queryType;
        cin >> queryType;

        if (queryType == "insert") {
            int data;
            cin >> data;
            tree.addNode(data);
        } else if (queryType == "contains") {
            int data;
            cin >> data;
            cout << (tree.findNode(data) ? "Yes" : "No") << endl;
        } else if (queryType == "size") {
            cout << tree.countNodes() << endl;
        } else if (queryType == "print") {
            cout << tree << endl;
        }
    }

    return 0;
}