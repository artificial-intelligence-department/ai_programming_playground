#include <iostream>
#include <string>

using namespace std;

template <typename T> class Node {
public:
    T value;
    Node* left = NULL;
    Node* right = NULL;
    
    Node(T newValue) {
        this->value = newValue;
    }
    
    template <typename U> friend ostream& operator<<(ostream&, const Node<U>&);
};

template <typename T> ostream& operator<<(ostream& out, const Node<T>& node) {
    if (node.left != NULL) {
        out << (*node.left);
    }
    
    out << node.value << " ";
    
    if (node.right != NULL) {
        out << (*node.right);
    }
    return out;
}

template <typename T> class Tree {
    
    Node<T>* root = NULL;
    
    void calculateSize(int& s, Node<T>* point) {
        if (point != NULL) {
            s++;
            if (point->left != NULL) {
                calculateSize(s, point->left);
            }
            if (point->right != NULL) {
                calculateSize(s, point->right);
            }
        }
    }
    
    void contains(bool& valueFound, T value, Node<T>* point) {
        if (valueFound) {
            return;
        }
        if (point != NULL) {
            if (point->value == value) {
                valueFound = true;
                return;
            }
            if (point->left != NULL) {
                contains(valueFound, value, point->left);
            }
            if (point->right != NULL) {
                contains(valueFound, value, point->right);
            }
        }
    }
    
    void insert(Node<T>* node, T newValue) {
        if (root == NULL) {
            root = new Node<T>(newValue);
            return;
        }
        else {
            if (newValue == node->value) {
                return;
            }
            else if (newValue < node->value) {
                if (node->left == NULL) {
                    node->left = new Node<T>(newValue);
                    return;
                }
                else {
                    insert(node->left, newValue);
                    return;
                }
            }
            else /* means (newValue > node->value) */ {
                if (node->right == NULL) {
                    node->right = new Node<T>(newValue);
                    return;
                }
                else {
                    insert(node->right, newValue);
                    return;
                }
            }
        }
    }
    
public:
    
    void insert(T newValue) {
        insert(this->root, newValue);
    }
    
    void size() {
        int sizeValue = 0;
        calculateSize(sizeValue, root);
        cout << sizeValue << "\n";
    }
    
    void contains(T value) {
        bool valueFound = false;
        contains(valueFound, value, root);
        cout << ((valueFound) ? "Yes" : "No") << "\n";
    }
    
    template <typename U> friend ostream& operator<<(ostream&, const Tree<U>&);
};

template <typename T> ostream& operator<<(ostream& out, const Tree<T>& tree) {
    if (tree.root != NULL) {
        out << (*tree.root);
    }
    return out;
}


int main() {
    int Q;
    cin >> Q;
    Tree<int> tree;
    
    for (int j = 0; j < Q; j++) {
        string operationStr;
        cin >> operationStr;
        
        if (operationStr == "insert") {
            int newValue;
            cin >> newValue;
            tree.insert(newValue);
        }
        else if (operationStr == "contains") {
            int findValue;
            cin >> findValue;
            tree.contains(findValue);
        }
        else if (operationStr == "size") {
            tree.size();
        }
        else if (operationStr == "print") {
            cout << tree << "\n";
        }
        else {
            cout << "unsupported operation: " << operationStr <<"\n";
        }
    }
    
    return 0;
}