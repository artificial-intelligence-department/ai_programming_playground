#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int appendedData)
    {
        data = appendedData;
        prev = NULL;
        next = NULL;
    }
    
};
class List
{
    public:
    Node* head;
    Node* tail;
    public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    Node* push_front(int pushData)
    {
        Node* newNode = new Node(pushData);
        newNode -> next = head;
        if (head != NULL)   
            head -> prev = newNode;
        if (tail == NULL)
            tail = newNode;
        head = newNode;
        return newNode;
    }

    Node* push_back(int pushData)
    {
        Node* newNode = new Node(pushData);
        newNode -> next = NULL;
        newNode -> prev = tail;
        if (head == NULL)
            head = newNode;
        if (tail != NULL)
            tail -> next = newNode;
        tail = newNode;
        return newNode;   
    }
    
    void printList (Node* head)
    {   
        if (head == NULL)
        {
            return;
        }  
        Node* ptr = head -> next;
        Node* temp = NULL;
        cout << head -> data << "\t";
        while (ptr != NULL)
        {
          
            cout << ptr -> data << "\t";
            ptr = ptr -> next;
        }
    }

    void reverse (Node*& head)
    {   
        if (head == NULL)
        {
            return;
        }   
        Node* ptr = head;
        Node* buff = NULL;
        while (ptr != NULL)
        {   
            buff = ptr -> prev;
            ptr -> prev = ptr -> next;
            ptr -> next = buff;
            head = ptr;
            ptr = ptr -> prev;
        }
    }
};

int main()
{
    int i, n, input;
    cout << "Write a number of elements" << endl;
    cin >> n;
    List newList;
    Node* temp = NULL;
    Node* ptr;
    
    cout << "Add the elements" << endl;
    while(n > 0)
    {
        cin >> input;
        newList.push_back(input); 
        n--;
    }
    newList.reverse(newList.head);
    cout << "Reversed list:" << endl;
    newList.printList(newList.head);
    return 0;
}