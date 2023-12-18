#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};

void add_tree_node(Node *&root, int key)
{
    if (root == nullptr)
    {
        root = new Node{ key, nullptr, nullptr };
        return;
    }

    if (key < root->key)
    {
        add_tree_node(root->left, key);
    }
    else
    {
        add_tree_node(root->right, key);
    }
}

void in_order(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    in_order(root->left);
    cout << root->key << " ";
    in_order(root->right);
}

Node *create_mirror_flip(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    Node *newRoot = new Node{ root->key, nullptr, nullptr };

    newRoot->left = create_mirror_flip(root->right);
    newRoot->right = create_mirror_flip(root->left);

    return newRoot;
}

void tree_sum(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->left != nullptr || root->right != nullptr)
    {
        int sum = 0;
        if (root->left != nullptr)
        {
            sum += root->left->key;
        }
        if (root->right != nullptr)
        {
            sum += root->right->key;
        }

        root->key = sum;
    }

    tree_sum(root->left);
    tree_sum(root->right);
}

int main()
{
    Node *root = nullptr;

    add_tree_node(root, 5);
    add_tree_node(root, 2);
    add_tree_node(root, 3);
    add_tree_node(root, 4);
    add_tree_node(root, 1);

    in_order(root);
    cout << endl;

    Node *mirror_Root = create_mirror_flip(root);

    in_order(mirror_Root);
    cout << endl;

    tree_sum(root);
    in_order(root);

    return 0;
}