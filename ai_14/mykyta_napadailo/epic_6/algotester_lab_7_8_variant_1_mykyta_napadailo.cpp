#include <iostream>
using namespace std;

struct Node 
{
    int key;
    Node *left, *right;
};

Node* newTree(int value)
{
    Node *root = new Node;
    root -> key = value;
    root -> left = root -> right = nullptr;
    return root;
}

Node* insert(Node *parent, int value)
{
    if (parent == nullptr)
    {
        parent = newTree(value);
        return parent;
    }
    if (value == parent -> key) return parent;
    if (value < parent -> key) parent -> left = insert(parent -> left, value);
    else parent -> right = insert(parent -> right, value);
    return parent;
}

bool contains(Node *parent, int value, bool present = false)
{
    if (parent == nullptr) return false;
    if (value == parent -> key || present)
    {
        present = true;
        return true;
    } 

    if (value < parent -> key) return contains(parent -> left, value, present);
    else return contains(parent -> right, value, present);
}

void print(Node *parent)
{
    if (parent != nullptr) 
    {
        print(parent -> left);
        cout << parent -> key << ' ';
        print(parent -> right);
    }
}

int size(Node *parent)
{
    if (parent == nullptr) return 0;
    else return 1 + size(parent -> left) + size(parent -> right);
}


int main()
{
    int Q;
    cin >> Q;
    Node *r = nullptr;
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
                r = insert(r, value);
                break;
            }
            case 'c':
            {
                int value;
                cin >> value;
                cout << (contains(r, value) ? "Yes\n" : "No\n");
                break;
            }
            case 's':
            {
                cout << size(r) << endl;
                break;
            }
            default:
            {
                print(r);
            }
        }
    }
}