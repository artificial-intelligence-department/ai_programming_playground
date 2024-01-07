#include<iostream>
#include<stack>
using namespace std;

struct TreeN
{
    int element;
    TreeN* right;
    TreeN* left;
    
    TreeN(int el) : element(el), left(NULL), right(NULL) {}
};

void printFUNC(TreeN* root )
{
    if(root != NULL)
    {
        printFUNC(root -> left);

        cout<<root -> element<<"  ";
        
        printFUNC(root -> right);
    }
}

void sumFUNC(TreeN* root) {
    if (root == NULL) 
    {
        return;
    }

    sumFUNC(root->left);
    sumFUNC(root->right);

    int number = root -> element;

    if (root -> left) 
    {
        number += root -> left -> element;
    }
    if (root -> right) 
    {
        number += root -> right -> element;
    }

    root -> element = number;
}

int main()
{
    TreeN* root = new TreeN(9);
    root -> left = new TreeN(8);
    root -> right = new TreeN(7);
    root -> left -> right = new TreeN(6);
    root -> right -> left = new TreeN(1);
    root -> right -> right = new TreeN(11);

    cout<<"Binary tree is: "<<endl;
    printFUNC(root);

    cout<<endl;

    sumFUNC(root);

    cout<<"Sum of the tree is: "<<endl;
    printFUNC(root);

    return 0;
}