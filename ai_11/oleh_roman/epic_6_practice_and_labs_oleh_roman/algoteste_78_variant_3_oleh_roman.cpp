#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T key;
        Node* prev;
        Node* next;

        Node(const T& k) : key(k), prev(nullptr), next(nullptr) {}
    };

    Node* head;

    void insert(Node*& node, const T& value) {
        if (!node) {
            node = new Node(value);
        } else {
            if (value < node->key) {
                insert(node->prev, value);
            } else if (value > node->key) {
                insert(node->next, value);
            }
        }
    }

    bool contains(Node* node, const T& value) const {
        while (node) {
            if (value == node->key) {
                return true;
            } else if (value < node->key) {
                node = node->prev;
            } else {
                node = node->next;
            }
        }
        return false;
    }


    int size(Node* node) const {
        if (!node) {
            return 0;
        }
        return 1 + size(node->prev) + size(node->next);
    }

    void print(Node* node) const {
        if (node) {
            print(node->prev);
            cout << node->key << " ";
            print(node->next);
        }
    }

public:
    BinarySearchTree() : head(nullptr) {}

    void insert(const T& value) {
        insert(head, value);
    }

    bool contains(const T& value) const {
        return contains(head, value);
    }

    int size() const {
        return size(head);
    }

    void print() const {
        print(head);
        cout << endl;
    }
};

int main() {
    BinarySearchTree<int> bst;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        string command;
        cin >> command;

        if (command == "insert") {
            int value;
            cin >> value;
            bst.insert(value);
        } else if (command == "contains") {
            int value;
            cin >> value;
            cout << (bst.contains(value) ? "Yes" : "No") << endl;
        } else if (command == "size") {
            cout << bst.size() << endl;
        } else if (command == "print") {
            bst.print();
        }
    }

    return 0;
}
