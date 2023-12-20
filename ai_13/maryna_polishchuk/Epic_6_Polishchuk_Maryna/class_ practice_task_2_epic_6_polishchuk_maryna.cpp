#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* next;
};


class LinkedList
{
private:
    Node head;
    Node tail;
public:
    LinkedList() // нічого не повертає, але створює елемент класу
    {
        head.next = &tail;
        tail.next = nullptr;
    }

    Node* start() {
        return head.next;
    }

    //вставка елементів
    void push(char data) {
        insert_after(head, data);
    }

    void insert_after(Node &after, char value)
    {
        Node* newNode = new Node(); 
        newNode->data = value; // записуємо

        newNode->next = after.next;
        after.next = newNode;

        length++;
    }

        // 2. Написати функцію для друку списку.
    void print()
    {
        Node* node = start(); //ми створюємо, який буде посиланням на початок списку
        
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

    int length = 0;
    bool compareWith(LinkedList &secondList)
    {
        if(length != secondList.length)
            return false;
        
        Node* n1 = start();
        Node* n2 = secondList.start();

        while (n1->next != nullptr)
        {
            if (n1->data != n2->data)
                return false;

            n1 = n1->next;
            n2 = n2->next;
        }
        
        return true;
    }
};


int main()
{
        
    LinkedList list = LinkedList();
    LinkedList list2 = LinkedList();

    for (int i = 0; i < 6; i++)
    {
        list.push(i);
        list2.push(i);
    }

    list.print();
    list2.print();
    
    list.compareWith(list2) ? cout << "equal" : cout << "different";
    cout << endl;

    list.push(5);
    list2.push(-5);
    list.print();
    list2.print();

    list2.compareWith(list) ? cout << "equal" : cout << "different";

    return 0;

}
