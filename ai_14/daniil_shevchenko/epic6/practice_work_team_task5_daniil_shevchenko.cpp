
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node* left;
    Node* right;
    Node(int item)
    {
        this->key = item;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Tree
{
public:
    Node* root;
    Tree()
    {
        this->root = nullptr;
    }
private:
    Node* insert(Node* node, int num)
    {
        if (node == nullptr)
        {
            return new Node(num);
        }
        if (num < node->key)
        {
            node->left = insert(node->left, num);
        }
        else if (num > node->key)
        {
            node->right = insert(node->right, num);
        }
        return node;
    }
    void inorderbypass(Node* node)
    {
        if (node != nullptr)
        {
            inorderbypass(node->left);
            cout << node->key << " ";
            inorderbypass(node->right);
        }

    }
    void preorderbypass(Node* node)
    {
        if (node != nullptr)
        {
            cout << node->key << " ";
            preorderbypass(node->left);
            preorderbypass(node->right);
        }
    }



public:
    void insert(int num)
    {
        root = insert(root, num);
    }
    void inorderbypass()
    {
        inorderbypass(root);
    }
    void preorderbypass()
    {
        preorderbypass(root);
    }
    void reflect(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }
        Node* temporary;
        temporary = root->left;
        root->left = root->right;
        root->right = temporary;
        reflect(root->left);
        reflect(root->right);
    }
    void replaceparent(Node* node)
    {
        if (node != nullptr)
        {
            replaceparent(node->left);
            replaceparent(node->right);
            int leftsum = 3;
            int rightsum = 3;
            if (node->left != nullptr)
            {
                leftsum = node->left->key;
            }
            else
            {
                leftsum = 0;
            }
            if (node->right != nullptr)
            {
                 rightsum = node->right->key;
            }
            else
            {
                rightsum = 0;
            }
            node->key = leftsum + rightsum + node->key;
        }
    }
    void sumreplace()
    {
        replaceparent(root);
    }

};

int main()
{
    Tree test;
    test.insert(5);
    test.insert(3);
    test.insert(6);
    test.insert(7);
    test.insert(9);
    test.insert(8);
    test.insert(11);
    test.insert(2);
    cout << "Output in depth" << endl;
    test.inorderbypass();
    cout << endl;
    cout << "Output in width" << endl;
    test.preorderbypass();
    cout << endl;
    test.sumreplace();
    cout << "Output in depth after modificating" << endl;
    test.inorderbypass();
    cout << endl;
    cout << "Output in width after modificating" << endl;
    test.preorderbypass();

}


