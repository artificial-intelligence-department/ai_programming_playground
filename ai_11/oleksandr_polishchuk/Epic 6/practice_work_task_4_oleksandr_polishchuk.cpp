#include <iostream>
#include <cmath>

using namespace std;

class Node
{
    public:
    int data;
    Node* right;
    Node* left;
    public:
    Node(int appendedData)
    {
        data = appendedData;
        right = NULL;
        left = NULL;
    }
      
};
class Tree
{
    public:
    Node* root;
    Tree()
    {
        root = NULL;
    }
    void insert(int appendData)
    {
        if (root == NULL)
        {
            root = new Node (appendData);
            return;
        }
        Node* newNode = root;
        while(newNode != NULL)
        { 
            if(newNode -> data == appendData)
            {
                return;
            }
            else if (appendData > newNode -> data)
            {
                if(newNode -> right == NULL)
                {
                    newNode -> right = new Node(appendData);
                    return;
                }
                else newNode = newNode -> right;
            }
            else if(appendData < newNode -> data)
            {
                if(newNode -> left == NULL)
                {
                    newNode -> left = new Node(appendData);
                    return;
                }
                else newNode = newNode -> left;
            }
        } 
    }
    void printTree(Node* node)
    {
        if (node != NULL)
        {
            if (node->left != NULL)
            {
                printTree(node->left);
            }

            cout << node->data << "\t";

            if (node->right != NULL)
            {
                printTree(node->right);
            }
           
        }
    }
};


Node* create_mirror_flip(Node* root)
{
    
    Node* node = root;
    if(node != NULL)
    {   
        Node* buff = node -> left;
        node -> left = node -> right;
        node -> right = buff;
        create_mirror_flip(node -> left);
        create_mirror_flip(node -> right);
    }
    
    return node;
}
Tree create_mirror_flip(Tree tree)
{
    tree.root = create_mirror_flip(tree.root);
    return tree;
}


int main()
{
    Tree newTree;
    Tree mirrorTree;
    newTree.insert(8);
    newTree.insert(6);
    newTree.insert(10);
    newTree.insert(2);
    newTree.insert(11);
    newTree.insert(9);
    newTree.insert(7);
    newTree.printTree(newTree.root);
    mirrorTree = create_mirror_flip(newTree);
    cout << "\n" << "Mirror tree: " << endl;
    newTree.printTree(mirrorTree.root);
    return 0;
}