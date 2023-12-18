#include <iostream>
#include <vector>
using namespace std;

struct Input
{
    string command;
    int argument;
};

template <class T>
class BinaryTree
{
    class Node
    {
    public:
        T data;
        Node *left;
        Node *right;
        Node *parent;
    };

private:
    Node *head = NULL;
    int size = 0;

public:
    int getSize()
    {
        return size;
    }

    void addElement(Node *branchHead, Node *node)
    {
        if (node == NULL)
            return;
        if (branchHead == NULL)
        {
            head = node;
            size++;
            return;
        }

        Node *current = branchHead;

        if (current->data < node->data)
        {
            if (current->right == NULL)
            {
                size++;
                current->right = node;
                node->parent = current;
                node->left = NULL;
                node->right = NULL;
                return;
            }
            addElement(current->right, node);
        }
        else if (current->data > node->data)
        {
            if (current->left == NULL)
            {
                size++;
                current->left = node;
                node->parent = current;
                node->left = NULL;
                node->right = NULL;
                return;
            }
            addElement(current->left, node);
        }
    }
    void addElement(T value)
    {
        Node *node = new Node();
        node->data = value;
        addElement(head, node);
    }

    void print(Node *node)
    {
        if (node == NULL)
            return;
        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }

    void doesContain(Node *node, T value)
    {
        Node *current = node;
        if (current == NULL)
        {
            cout << "No";
            return;
        }
        else
        {
            if (current->data == value)
            {
                cout << "Yes";
                return;
            }
            else
            {
                if (current->data < value)
                {
                    doesContain(current->right, value);
                }
                else
                {
                    doesContain(current->left, value);
                }
            }
        }
    }

    void doesContain(T value)
    {
        doesContain(head, value);
    }

    void print()
    {
        print(head);
    }
};

int main()
{
    int q;
    cin >> q;

    BinaryTree<int> tree;
    vector<Input> inputs;

    for (int i = 0; i < q; i++)
    {
        string command;
        cin >> command;
        Input inp;
        inp.command = command;
        if (command == "insert" || command == "contains")
        {
            int input;
            cin >> input;
            inp.argument = input;
        }

        inputs.push_back(inp);
    }

    for (int i = 0; i < inputs.size(); i++)
    {
        string command = inputs[i].command;
        if (command == "size")
        {
            cout << tree.getSize() << "\n";
        }
        else if (command == "print")
        {
            tree.print();
            cout << "\n";
        }
        else if (command == "insert" || command == "contains")
        {
            int argument = inputs[i].argument;

            if (command == "insert")
            {
                tree.addElement(argument);
            }
            else
            {
                tree.doesContain(argument);
                cout << "\n";
            }
        }
    }

    return 0;
}