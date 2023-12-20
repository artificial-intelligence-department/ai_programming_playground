#include<iostream>
using namespace std;

struct Node {
    int element;
    Node* left;
    Node* right;

    Node(int el) : element(el), left(NULL), right(NULL) {}
};

void insertFUNC(Node*& root, int number) 
{
    if (root == NULL) 
    {
        root = new Node(number);
        return;
    }

    if (number == root -> element) 
    {
        return;
    }

    if (number < root -> element) 
    {
        insertFUNC(root -> left, number);
    } 
    else 
    {
        insertFUNC(root -> right, number);
    }
}

void addFUNC(Node*& root, int number2)
{
    insertFUNC(root, number2);
}

void printFUNC(Node* root )
{
    if(root != NULL)
    {
        printFUNC(root -> left);

        cout<<root -> element<<"  ";
        
        printFUNC(root -> right);
    }
}

int sizeFUNC(Node* root) {
    if (root == NULL) 
    {
        return 0;
    } 
    else
    {
        int counter = 1; 

        counter += sizeFUNC(root -> left);
        counter += sizeFUNC(root -> right);

        return counter;
    }
}

bool searchFUNC(Node* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root -> element == key) 
    {
        return true;
    } 
    else if (key < root -> element) 
    {
        return searchFUNC(root -> left, key);
    } 
    else 
    {
        return searchFUNC(root -> right, key);
    } 
}

int main() {
    Node* root = NULL;
    int number_in_main, repeat;

    cin >> repeat;

    for (int i = 0; i < repeat; i++) 
    {
        string action;
        cin >> action;

        if (action == "contains") 
        {
            int number_to_find;
            cin >> number_to_find;
            bool founder = searchFUNC(root, number_to_find);

            if (founder) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } 
        else if (action == "size") 
        {
            int result = sizeFUNC(root);
            cout << result << endl;
        } 
        else if (action == "print") 
        {
            printFUNC(root);
            cout << endl;
        } 
        else if (action == "insert") 
        {
            cin >> number_in_main;
            addFUNC(root, number_in_main);

            cout<<endl;
        }
    }

    return 0;
}
