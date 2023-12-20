#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
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

    Node* start() {
        return head.next;
    }

    Node* end() {
        return tail.prev;
    }
    
    void push(int data) {
        insert_after(head, data);
    }

    void push_back(int data) {
        insert_after(*tail.prev, data);
    }

    void insert_after(Node &after, int value)
    {
        Node* newNode = new Node(); 
        newNode->data = value;

        newNode->next = after.next;
        newNode->prev = &after;
        after.next->prev = newNode;
        after.next = newNode;
    }

    void print()
    {
        Node* node = start();
        
        if(node->next == nullptr)
        {
            cout << "list is empty...\n";
            return;
        }

        while(node->next != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    dll reverse()
    {
        dll copy = dll();

        for (Node* node = start(); node->next != nullptr; node = node->next)
            copy.push(node->data);
        
        return copy;
    }
};


int main()
{      
    dll list = dll();
        cout << "origin list: \n";
    int k = 4;
    for (int i = 0; i < k; i++)
    {
        list.push(i);
        list.push_back(-i - 5);
    }

    list.print();

    list = list.reverse();

    cout << "reverse list: \n";
    list.print();

    return 0;
}
