#include<iostream>
#include<string>
using namespace std;

class Node 
{
public:
    string element;
    Node* next;
}; 

Node* reverseFUNC(Node* head)
{
    Node* current = head;
    Node* previous = NULL;
    Node* future = NULL;

    while (current != NULL)
    {
        future = current -> next;
        current -> next = previous;
        previous = current;
        current = future;
    }

    return previous;
}

void printFUNC(Node* el)
{
    while (el != NULL)
    {
        cout << el -> element <<"  ";
        el = el -> next;
    }
}

int main()
{
    Node* headd = NULL;
    Node* middle = NULL;
    Node* tail = NULL;

    headd = new Node();
    middle = new Node();
    tail = new Node();

    headd -> element = "BMW";
    headd -> next = middle;

    middle -> element = "Audi";
    middle -> next = tail;

    tail -> element = "Mercedes-Benz";
    tail -> next = NULL;

    cout << "Linked list is: ";
    printFUNC(headd);

    cout <<endl<< "Reversed list is: ";
    Node* reversed = reverseFUNC(headd);
    printFUNC(reversed);

    return 0;
}
