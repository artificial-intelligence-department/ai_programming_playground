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
};

Node* nodeSum(Node* n1, Node* n2) 
{
    dll* result = new dll();

    int over = 0;
    while (n1 || n2 || over) {
        int sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + over;
        over = sum / 10;

        result->pushBack(sum % 10);

        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }

    return result->start();
}

int main()
{
    dll list1 = dll();
    dll list2 = dll();

    list1.push(1);
    list1.push(5);
    list1.push(0);

    list2.push(5);
    list2.push(5);

    list1.print();
    list2.print();

    cout << "expected sum: 150 + 55 = 205" << endl;
    cout << "result: ";

    Node* result = new Node();
    result = nodeSum(list1.start(), list2.start());
    
    while(result != nullptr)
    {
        result = result->next;
        cout << result->data;
    }

    return 0;
}