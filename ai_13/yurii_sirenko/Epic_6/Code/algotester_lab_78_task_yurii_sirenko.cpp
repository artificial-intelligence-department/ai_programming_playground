#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class BinarySearchTree 
{
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    Node* insert(Node* node, const T& value) {
        if (node == nullptr) {
            size++;
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool contains(Node* node, const T& value) const {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return contains(node->left, value);
        } else {
            return contains(node->right, value);
        }
    }

    void printInOrder(Node* node) const {
        if (node != nullptr) {
            printInOrder(node->left);
            std::cout << node->data << " ";
            printInOrder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr), size(0) {}

    void insert(const T& value) {
        root = insert(root, value);
    }

    bool contains(const T& value) const {
        return contains(root, value);
    }

    int getSize() const {
        return size;
    }

    void print() const {
        printInOrder(root);
        std::cout << std::endl;
    }
};

int main() 
{
    int Q;
    cin >> Q;
    string operation;
    char operations[Q];
    int value[Q];

    BinarySearchTree <int> bst;
    for(int i = 0;i<Q;i++)
    {
        std::cin >> operation;
        char op = operation[0];
        switch (op) {
            case 'i': 
            {
                operations[i]=op;
                cin >> value[i];
                break;
            }
            case 'c': {
                operations[i]=op;
                cin >> value[i];
                break;
            }
            case 's': 
            {
                operations[i]=op;            
                break;
            }
            case 'p': 
            {
                operations[i]=op; 
                break;
            }
            default:

                break;
            }
    }
    for(int i = 0;i<Q;i++)
    {
        switch (operations[i]) {
            case 'i': {
                bst.insert(value[i]);
                break;
            }
            case 'c': {
                std::cout << (bst.contains(value[i]) ? "Yes" : "No") << std::endl;
                break;
            }
            case 's': {
                std::cout << bst.getSize() << std::endl;
                break;
            }
            case 'p': {
                bst.print();
                break;
            }
            default:

                break;
        }
    }

    return 0;
}
