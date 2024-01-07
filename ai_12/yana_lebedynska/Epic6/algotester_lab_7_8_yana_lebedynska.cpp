#include <iostream>
using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <class T>
class BinaryTree
{
    private:
        Node<T>* root;

        bool contains(Node<T>* node, T number)
        {
            if(node == nullptr)
            {
                return false;
            }

            if(number == node->data)
            {
                return true;
            }
            else if(number < node->data)
            {
                return contains(node->left, number);
            }
            else
            {
                return contains(node->right, number);
            }
        }


        Node<T>* insert(Node<T>* node, T number)
        {
            if(node == nullptr)
            {
                return new Node<T>(number);
            }

            if(number < node->data)
            {
                node->left = insert(node->left, number);
            }
            else if(number > node->data)
            {
                node->right = insert(node->right, number);
            }

            return node;
        }

        void print(Node<T>* node)
        {
            if(node != nullptr)
            {
                print(node->left);
                cout << node->data << " ";
                print(node->right);
            }
        }

        int count(Node<T>* node)
        {
            if(node == nullptr)
            {
                return 0;
            }
            else
            {
                return 1 + count(node->left) + count(node->right);
            }
        }

    public:
        BinaryTree() : root(nullptr) {} // за допомогою констурктора вказую, що при створенні нового дерева корінь буде вказувати спочатку на null pointer

        void insert(T number)
        {
            root = insert(root, number);
        }

        bool contains(T number)
        {
            return contains(root, number);
        }

        void print()
        {
            print(root);
            cout << endl;
        }

        int size()
        {
            return count(root);
        }
};

int main()
{
    int Q;
    cin >> Q;

    BinaryTree<int> tree;

    while(Q--) // поки Q не стане нулем при кожній ітерації
    {
        string operation;
        cin >> operation;

        if(operation == "insert")
        {
            int number;
            cin >> number;
            tree.insert(number);
        }
        else if(operation == "contains")
        {
            int number;
            cin >> number;

            if(tree.contains(number))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if(operation == "size")
        {
            cout << tree.size() << endl;
        }
        else if(operation == "print")
        {
            tree.print();
        }
    }

    return 0;
}
