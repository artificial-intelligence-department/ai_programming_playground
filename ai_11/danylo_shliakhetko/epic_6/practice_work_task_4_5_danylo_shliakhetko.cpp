#include <iostream>
#include <vector>
using namespace std;

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

    Node *mirrorTree(Node *node)
    {
        if (node == NULL)
        {
            return node;
        }

        Node *left = mirrorTree((node->left));
        Node *right = mirrorTree((node->right));
        node->left = right;
        node->right = left;

        return node;
    }

    void mirrorTree()
    {
        mirrorTree(head);
    }

    Node *sum(Node *node)
    {
        if (node == NULL)
        {
            return node;
        }

        Node *right = sum((node->right));
        Node *left = sum((node->left));
        if (left != NULL && right != NULL)
        {
            node->data = left->data + right->data;
        }
        else if (right == NULL && left != NULL)
        {
            node->data = left->data;
        }
        else if (left == NULL && right != NULL)
        {
            node->data = right->data;
        }

        return node;
    }

    void sum()
    {
        sum(head);
    }
};

int main()
{
    cout << "Task 4\n";
    BinaryTree<int> tree;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        tree.addElement(rand() % 100);
    }

    tree.print();
    cout << "\n";

    tree.mirrorTree();

    tree.print();

    cout << "\nTask 5\n";

    tree.print();
    cout << "\n";

    tree.sum();
    tree.print();

    return 0;
}