#include <iostream>
#include <functional>

// Algotester Lab 7-8 V3
// Binary Search Tree (AVL)

// https://www.youtube.com/watch?v=DB1HFCEdLxA
// https://www.youtube.com/watch?v=JPI-DPizQYk
// https://www.youtube.com/watch?v=PBkXmhiCP1M

// TODO: Add iterators
template <class T>
class AVL {
protected:
    struct Node {
    public:
        T value;
        int height;
        // Node* parent;
        Node* left;
        Node* right;

        Node(T value, int height, Node* left, Node* right)
                : value(value), height(height), left(left), right(right) {}

        Node()  : height(0), left(nullptr), right(nullptr) {}

        explicit Node(T value) : Node(value, 0, nullptr, nullptr) {}
    };

    // Helper for finalizer
    void delete_tree(Node* _root) {
        if (_root == nullptr) return;

        delete_tree(_root->left);
        delete_tree(_root->right);
        delete _root;
    }

    Node* find(T value) {
        Node* current = root;
        while (current != nullptr) {
            if (current->value == value) return current;
            if (value < current->value) current = current->left;
            else current = current->right;
        }
        return nullptr;
    }

    Node* _append_node(Node* node, T value) {
        if (node == nullptr) {
            _size++;
            return new Node(value);
        }

        // traverse the tree to find the right place for the new node
        if (value < node->value)
            node->left = _append_node(node->left, value);
        else if (value > node->value)
            node->right = _append_node(node->right, value);

        // Balance the tree

        // Update height of the root
        const int   left_height     = height(node->left),
                    right_height    = height(node->right);
        // determine height of root (max of left or right subtree + 1)
        // (because it is the longest path from root to leaf)
        node->height = 1 + std::max(left_height, right_height);

        // determine balance factor
        const int balance_factor = left_height - right_height;

        // if balance_factor is greater than 1
        // then tree is left heavy -> right rotation
        if (balance_factor > 1) {
            if (value < node->left->value) {
                return right_rotation(node);
            } else {
                // left rotation on left subtree (because it is right heavy)
                node->left = left_rotation(node->left);
                return right_rotation(node);
            }
        }
        // if balance_factor is less than -1
        // then tree is right heavy -> left rotation
        else if (balance_factor < -1) {
            if (value > node->right->value) {
                return left_rotation(node);
            } else {
                // right rotation on right subtree (because it is left heavy)
                node->right = right_rotation(node->right);
                return left_rotation(node);
            }
        }
        return node;
    }

    Node* _remove_node(Node* node, T value) {
        if (node == nullptr) return nullptr;

        // traverse the tree to find the right node
        if (value < node->value) {
            node->left = _remove_node(node->left, value);
        } else if (value > node->value) {
            node->right = _remove_node(node->right, value);
        } else /* if reached the value */ {
            Node *r = node->right;
            if (node->right == nullptr) {
                Node *l = node->left;
                delete node;
                node = l;
            } else if (node->left == nullptr) {
                delete node;
                node = r;
            } else /* if both leaves are present */ {
                // find the smallest value in the right subtree
                while (r->left != nullptr) r = r->left;

                // and replace the root with it
                node->value = r->value;
                node->right = _remove_node(node->right, r->value);
            }
        }

        if (node == nullptr) return nullptr;

        // Balance the tree

        // Update height of the root
        const int   left_height = height(node->left),
                    right_height = height(node->right);
        // determine height of root (max of left or right subtree + 1)
        // (because it is the longest path from root to leaf)
        node->height = 1 + std::max(left_height, right_height);

        // determine balance factor
        const int balance_factor = left_height - right_height;
        if (balance_factor > 1) {
            if (height(node->left) >= height(node->right))
                return right_rotation(node);
            else {
                node->left = left_rotation(node->left);
                return right_rotation(node);
            }
        } else if (balance_factor < -1) {
            if (height(node->right) >= height(node->left))
                return left_rotation(node);
            else {
                node->right = right_rotation(node->right);
                return left_rotation(node);
            }
        }
        return node;
    }

    static size_t height(const Node* node) {
        return node == nullptr ? 0 : node->height;
    }

    Node* right_rotation(Node* _root) {
        // new root is the left child of the old root
        // (anti-clockwise rotation)
        Node *new_root = _root->left;

        _root->left = new_root->right;
        // new root's right child is the old root
        new_root->right = _root;

        // update heights
        _root->height = 1 + std::max(
                height(_root->left),
                height(_root->right)
        );
        new_root->height = 1 + std::max(
                height(new_root->left),
                height(new_root->right)
        );

        return new_root;
    }

    Node* left_rotation(Node* _root){
        // new root is the right child of the old root
        // (clockwise rotation)
        Node* new_root = _root->right;

        _root->right = new_root->left;
        // new root's left child is the old root
        new_root->left = _root;

        // update heights
        _root->height = 1 + std::max(
                height(_root->left),
                height(_root->right)
        );
        new_root->height = 1 + std::max(
                height(new_root->left),
                height(new_root->right)
        );

        return new_root;
    }

private:
    Node* root;
    int _size;

public:
    enum Traversal {
        PREORDER,
        INORDER,
        POSTORDER
    };

    AVL() {
        root = nullptr;
        _size = 0;
    }

    AVL(std::initializer_list<T> list) {
        root = nullptr;
        _size = 0;
        for (auto value : list) {
            emplace(value);
        }
    }

    ~AVL() {
        delete_tree(root);
    }

    // Nodiscard is used to warn the user if the return value is ignored
    // (Function is useless if we just call it)
    [[nodiscard]] int size() const {
        return _size;
    }

    void emplace(T value) {
        root = _append_node(root, value);
    }

    bool contains(T value) {
        return find(value) != nullptr;
    }

    void remove(T value) {
        root = _remove_node(root, value);
    }

    void forEach(std::function<void(T)> func, Traversal traversal = Traversal::INORDER) {
        std::function<void(Node*)> _func = [&](Node* node) {
            if (node == nullptr) return;
            if (traversal == Traversal::PREORDER) func(node->value);
            _func(node->left);
            if (traversal == Traversal::INORDER) func(node->value);
            _func(node->right);
            if (traversal == Traversal::POSTORDER) func(node->value);
        };
        _func(root);
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, AVL<T>& _tree) {
    _tree.forEach([&](T value) {
        os << value << " ";
    }, AVL<T>::Traversal::INORDER);
    return os;
}

int main() {
    using namespace std;
    AVL<int> tree;

    int queries;
    string query;
    cin >> queries;

    for (int i = 0; i < queries; ++i) {
        cin >> query;

        try {
            if (query == "insert") {
                int element;
                cin >> element;
                tree.emplace(element);
            }  else if (query == "size") {
                cout << tree.size() << endl;
            }  else if (query == "print") {
                cout << tree << endl;
            } else if (query == "contains") {
                int element;
                cin >> element;
                cout << (tree.contains(element) ? "Yes" : "No") << endl;
            } else if (query == "remove") {
                int element;
                cin >> element;
                tree.remove(element);
            }
        }
        catch (out_of_range&) {}
        catch (exception&) {}
    }

    return 0;
}
