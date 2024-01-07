#include<iostream>
using namespace std;

class Node
{
    public:
    int element;
    Node* next = NULL;
    Node* previous = NULL;
};

void printFUNC(Node* number)
{
    while(number != NULL)
    {
        cout<<number -> element<<"  ";
        number = number -> next;
    }
}

Node* deleteFUNC(Node* head, int element2) 
{ 
    while (head && head -> element == element2)
    { 
        head = head -> next; 
    }
    Node *current = head, *previous = NULL; 
  
    while (current) 
    { 
        if (current -> element == element2) 
            previous -> next = current -> next; 
        else
            previous = current; 
        current = current -> next; 
    } 
    return head; 
} 

void addFUNC(Node* head, int number_of_elements) 
{
    Node* current = head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }
    for (int i = 0; i < number_of_elements; i++) 
    {
        Node* new_Node = new Node();
        cout << "Enter element: "<< ": ";
        int elements;
        cin >> elements;
        
        new_Node -> element = elements;
        current -> next = new_Node;
        current = new_Node;
    }
}

int main()
{
    Node* head = NULL;
    Node* middle = NULL;
    Node* tail = NULL;

    head = new Node();
    middle = new Node();
    tail = new Node();

    head -> element = 3;
    head -> next = middle;

    middle -> element = 18;
    middle -> next = tail;

    tail -> element = 2;
    tail -> next = NULL;

    printFUNC(head);

    cout<<endl;

    cout<<"Enter a key which you want to delete: "<<endl;

    int key;

    cin>>key;

    cout<<"Key succesfully deleted!"<<endl<<endl;
    cout<<"List after deleting: "<<endl;

    deleteFUNC(head, key);

    cout<<endl;

    printFUNC(head);

    cout<<endl;

    int adder;

    cout<<"Enter how many elements you want to add to linked-list: "<<endl;
    cin>>adder;

    cout<<"Enter every element: "<<endl;

    addFUNC(head, adder);

    cout<<endl;

    cout<<"List afther that action: "<<endl;

    printFUNC(head);

    cout<<endl;

    return 0;
}