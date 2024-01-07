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

int calculate(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left_sum = calculate(root->left);
    int right_sum = calculate(root->right);

    int total_sum = left_sum + right_sum + root->data;

    if (root->left != nullptr || root->right != nullptr)
    {
        int temp = root->data;
        root->data = left_sum + right_sum;
        return total_sum - temp;
    }

    return total_sum;
};

void tree_sum(Node* root)
{
    calculate(root);
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

    tree_sum(binary_tree.get_root());

    cout << "New tree:" << endl;
    print_tree(binary_tree.get_root());

    return 0;
}
