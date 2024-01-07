#include<iostream>

using namespace std;

class Node {
public:
    Node* next;
    int element;

    Node(int el1) : element(el1), next(NULL) {}
};

void PrintFUNC(Node* el) 
{
    while (el != NULL) 
    {
        cout << el -> element <<"   ";
        el = el -> next;
    }
}

Node* addFUNC(Node* num, Node* num2) 
{
    Node* start = NULL;
    Node* final = NULL;

    while (num != NULL && num2 != NULL) 
    {
        int sum = num -> element + num2 -> element;

        Node* newNode = new Node(sum);

        if (start == NULL) 
        {
            start = newNode;
            final = newNode;
        } 
        else 
        {
            final -> next = newNode;
            final = final -> next;
        }

        num = num->next;
        num2 = num2->next;
    }

    return start;
}

int main() {
    Node* num = new Node(9);
    num -> next = new Node(7);
    num -> next -> next = new Node(3);

    Node* num2 = new Node(1);
    num2 -> next = new Node(1);
    num2 -> next -> next = new Node(1);

    cout << "List 1: " << endl;
    PrintFUNC(num);

    cout<<endl;
    cout << "List 2: " << endl;
    PrintFUNC(num2);

    cout<<endl;
    cout << "Sum of lists: " << endl;
    Node* result = addFUNC(num, num2);
    PrintFUNC(result);

    return 0;
}
