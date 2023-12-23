#include <iostream>


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
    void insert(int appendData)
    {
        Node* newNode = this;
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
};
int sum(Node* node)
{
    int s = 0;
    if (node -> left != NULL)
        s += sum(node -> left);
    if (node -> right != NULL)
        s += sum(node -> right);
    if(node -> left == NULL && node -> right == NULL)
        s = node -> data;
    node -> data = s;
    return s;
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
Node* forNode (Node* node)
{
    if (node -> left != NULL)
        node = node -> left;
    if (node -> right != NULL)
        node = node -> right;
    node -> data = sum(node);
    
        return node;
}
int main()
{
    int a;
    Node* newTree = new Node(8);
    newTree -> insert(6);
    newTree -> insert(10);
    newTree -> insert(2);
    newTree -> insert(11);
    newTree -> insert(9);
    newTree -> insert(7);
    printTree(newTree);
    sum(newTree);
    cout << "\n" << "Sum :" << endl;
    printTree(newTree);

    return 0;
}
