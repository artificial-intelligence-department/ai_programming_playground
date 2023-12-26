#include <iostream>
using namespace std;

template <class T> struct Node 
{
    T key;
    Node<T> *left, *right;
};
template <class T> class BST 
{
    private: 
        Node<T> *root;

        Node<T>* newTree(T value)
        {
            Node<T> *root = new Node<T>;
            root -> key = value;
            root -> left = root -> right = nullptr;
            return root;
        }        

        Node<T>* insertPrivate(Node<T> *parent, T value)
        {
            if (parent == nullptr)
            {
                parent = newTree(value);
                return parent;
            }
            if (value == parent -> key) return parent;
            if (value < parent -> key) parent -> left = insertPrivate(parent -> left, value);
            else parent -> right = insertPrivate(parent -> right, value);
            return parent;
        }

        bool containsPrivate(Node<T> *parent, T value, bool present)
        {
            if (parent == nullptr) return false;
            if (value == parent -> key || present)
            {
                present = true;
                return true;
            } 
            if (value < parent -> key) return containsPrivate(parent -> left, value, present);
            else return containsPrivate(parent -> right, value, present);
        }

        void printPrivate(Node<T> *parent)
        {
            if (parent != nullptr) 
            {
                printPrivate(parent -> left);
                cout << parent -> key << ' ';
                printPrivate(parent -> right);
            }
        }

        int sizePrivate(Node<T> *parent)
        {
            if (parent == nullptr) return 0;
            else return 1 + sizePrivate(parent -> left) + sizePrivate(parent -> right);
        }

    public:
        BST() : root(nullptr) {}

        void insert(int value)
        {
            root = insertPrivate(root, value);
        }

        bool contains(int value)
        {
            return containsPrivate(root, value, false);
        }

        void print()
        {
            printPrivate(root);
        }

        int size()
        {
            return sizePrivate(root);
        }
};

int main()
{
    int Q;
    cin >> Q;
    BST<int> tree;
    while (Q--)
    {
        string request;
        cin >> request;
        switch (request[0])
        {
            case 'i':
            {
                int value;
                cin >> value;
                tree.insert(value);
                break;
            }
            case 'c':
            {
                int value;
                cin >> value;
                cout << (tree.contains(value) ? "Yes\n" : "No\n");
                break;
            }
            case 's':
            {
                cout << tree.size() << endl;
                break;
            }
            default:
            {
                tree.print();
            }
        } 
    }
}