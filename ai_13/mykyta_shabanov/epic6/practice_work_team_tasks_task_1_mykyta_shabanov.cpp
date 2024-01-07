#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class dll
{
private:
    Node head;
    Node tail;
public:
    dll()
    {
        head.prev = nullptr;
        head.next = &tail;

        tail.prev = &head;
        tail.next = nullptr;
    }
    int size = 0;

    Node* start() {
        return head.next;
    }

    void pushBack(int value) {
        insertAfter(*tail.prev, value);
    }

    void push(int value) {
        insertAfter(head, value);
    }

    void insertAfter(Node &after, int value)
    {
        Node* node = new Node();
        node->data = value;

            //main logic
        node->next = after.next;
        after.next->prev = node;

        after.next = node;
        node->prev = &after;

        size++;
    }

    void print()
    {
        if (size == 0)
        {
            cout << "List is empty..." << endl;
            return;
        }
        
        int i = 0;
        for (Node* list = head.next; list->next != nullptr && i < size; list = list->next, i++)
            cout << list->data << " ";

        cout << endl;
    }

    void reverse() 
    {
        Node* temp = nullptr;
        Node* current = head.next;

        while (current) 
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr)
            head.next = temp->prev;
    }
};

int main()
{
    dll list = dll();

    for (int i = 0; i <= 8; i++)
    {
        if(i < 5)
            list.push(i);
        else
            list.pushBack(i);
    }

    list.print();
    list.reverse();

        //output reverse list
    int i = 0;
    for (Node* print = list.start(); i < list.size; print = print->next, i++)
        cout << print->next->data << " ";
    
    
    return 0;
}