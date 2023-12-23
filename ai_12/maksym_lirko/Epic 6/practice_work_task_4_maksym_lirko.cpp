#include<iostream>
using namespace std;

struct TreeN
{
    int element;
    TreeN* left;
    TreeN* right;

    TreeN(int el) : element(el), left(NULL), right(NULL) {}
};

void printFUNC(TreeN* root)
{
    if(root != NULL)
    {
        printFUNC(root -> left);

        cout<<root -> element<<"  ";
        
        printFUNC(root -> right);
    }
}

TreeN* reversedFUNC(TreeN* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    else
    {
        TreeN* reversedTree = new TreeN(root -> element);
        
        reversedTree -> left = reversedFUNC(root -> right);
        reversedTree -> right = reversedFUNC(root -> left);
        
        return reversedTree;
    }
}



int main()
{
    TreeN* root = new TreeN(9);
    root -> left = new TreeN(8);
    root -> right = new TreeN(7);
    root -> left -> right = new TreeN(6);
    root -> right -> left = new TreeN(1);
    root -> right -> right = new TreeN(10);

    cout<<"Binary Tree is: "<<endl;
    
    printFUNC(root);

    cout<<endl;
    
    cout<<"Reversed tree: "<<endl;

    TreeN* result = reversedFUNC(root);
    
    printFUNC(result);
    return 0;
}