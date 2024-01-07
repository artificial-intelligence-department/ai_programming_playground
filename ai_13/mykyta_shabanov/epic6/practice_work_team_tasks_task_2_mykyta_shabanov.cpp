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

    bool compare(dll &another_dll)
    {
        if(size != another_dll.size)
            return false;
        else if(size == 0)
            return true;
        
        Node* n1 = start(); Node* n2 = another_dll.start();
        for (int i = 0; i < size; i++)
        {
            if (n1->data != n2->data)
                return false;
        }

        return true;        
    }
};

int main()
{
    dll list1 = dll();
    dll list2 = dll();

    for (int i = 0; i <= 8; i++)
    {
        if(i < 5)
        {
            list1.push(i);
            list2.push(i);
        }
        else
        {
            list1.pushBack(i);
            list2.pushBack(i);
        }
    }

    list1.print();

    list1.compare(list2) ? cout << "the lists are the same" : cout << "lists are different";
    cout << endl << "push back element>" << endl;
    list2.pushBack(1);
    list1.compare(list2) ? cout << "the lists are the same" : cout << "lists are different";
    
    return 0;
}