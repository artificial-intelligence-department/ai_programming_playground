#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* reverse(Node* head)
{
    Node* previous = nullptr;
    Node* next = nullptr;
    Node* current = head;

    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(6);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);

    cout << "The list before reversing: ";
    printList(head);

    head = reverse(head);
    cout << "The list after reversing: ";
    printList(head);

    return 0;
}
