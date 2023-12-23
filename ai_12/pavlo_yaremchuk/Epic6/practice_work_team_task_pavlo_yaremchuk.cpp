#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* AddToTree(Node* currnt, int data)
{
    if (currnt == nullptr)
    {
        return CreateNode(data);
    }

    if (data < currnt->data)
    {
        currnt->left = AddToTree(currnt->left, data);
    }

    if (data > currnt->data)
    {
        currnt->right = AddToTree(currnt->right, data);
    }

    return currnt;
}

void PrintTree(Node* root, int lvl = 0)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        PrintTree(root->right, lvl + 1);
        for (int i = 0; i < lvl; i++)
        {
            cout << "   ";
        }
        cout << root->data << endl;
        PrintTree(root->left, lvl + 1);
    }
}

Node* ReverseTree(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    Node* newRoot = CreateNode(root->data);
    newRoot->left = ReverseTree(root->right);
    newRoot->right = ReverseTree(root->left);

    return newRoot;
}


int main()
{
    Node* root = nullptr;

    root = AddToTree(root, 5);
    AddToTree(root, 3);
    AddToTree(root, 8);
    AddToTree(root, 1);
    AddToTree(root, 4);
    AddToTree(root, 7);
    AddToTree(root, 9);

    cout << "Звичайне:" << endl;
    PrintTree(root);

    Node* newRoot = ReverseTree(root);

    cout << "Віддзеркалене:" << endl;
    PrintTree(newRoot);

    return 0;
}