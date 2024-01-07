#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value): data(value), left(nullptr), right(nullptr)
    {

    }
};

class BinaryTree
{
    private:
    Node* root;

    Node* insert(Node* node, int value)
    {
        if(node == nullptr)
        {
            return new Node(value);
        }

        if(value < node -> data)
        {
            node -> left = insert(node -> left, value);
        }

        if(value > node -> data)
        {
            node -> right = insert(node -> right, value);
        }

        return node;
    };

    public:
    BinaryTree(): root(nullptr)
    {

    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    Node* get_root()
    {
        return root;
    }
};

Node* mirror_flip(Node* root)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    Node* current = root -> left;
    root -> left = mirror_flip(root-> right);
    root -> right = mirror_flip(current);

    return root;
};

void print_tree(Node* root, int level = 0) 
{
    if (root == nullptr) 
    {
        return;
    }

    const int indentation = 4;

    print_tree(root->right, level + 1);

    for (int i = 0; i < level * indentation; ++i) 
    {
        cout << " ";
    }

    cout << root->data << endl;

    print_tree(root->left, level + 1);
};

int main() 
{
    BinaryTree binary_tree;

    binary_tree.insert(5);
    binary_tree.insert(3);
    binary_tree.insert(7);
    binary_tree.insert(2);
    binary_tree.insert(4);
    binary_tree.insert(6);
    binary_tree.insert(8);

    cout << "Original tree:" << endl;
    print_tree(binary_tree.get_root());

    Node* mirrored_root = mirror_flip(binary_tree.get_root());

    cout << "Mirrored tree:" << endl;
    print_tree(mirrored_root);

    return 0;
}
