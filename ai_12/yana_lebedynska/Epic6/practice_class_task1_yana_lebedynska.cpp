#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* HEAD)
{
    Node* previous = nullptr;
    Node* next = nullptr;
    Node* current = HEAD;

    while(current != nullptr)
    {
        next = current->next;
        current->next = previous; //обертання (вказує не наступний вузол, а на попередній)
        previous = current; 
        current = next;
    }

    return previous;
}

void printList(Node* HEAD)
{
    while(HEAD != nullptr)
    {
        cout << HEAD->data << " ";
        HEAD = HEAD->next;
    }
    cout << endl;
}

int main()
{
    Node* HEAD = new Node(1);
    HEAD->next = new Node(2);
    HEAD->next->next = new Node(3);
    HEAD->next->next->next = new Node(4);

    cout << "The list BEFORE reversing: ";
    printList(HEAD);

    HEAD = reverse(HEAD);
    cout << "The list AFTER reversing: ";
    printList(HEAD);

    return 0;
}
