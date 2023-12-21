#include <iostream>
using namespace std;

class Node
{
public:
    const char *data;
    Node *next;
};

void printLinkedList(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

Node *reverseLinkedList(Node *head)
{
    Node *back = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = back;
        back = current;
        current = next;
    }

    return back;
}

bool compareLinkedLists(Node *L1, Node *L2)
{
    while (L1 != nullptr && L2 != nullptr)
    {
        if (L1->data != L2->data)
        {
            return false;
        }
        L1 = L1->next;
        L2 = L2->next;
    }
    return (L1 == nullptr && L2 == nullptr);
}

int main()
{
    Node *head1 = nullptr;
    Node *second1 = nullptr;
    Node *third1 = nullptr;

    head1 = new Node();
    second1 = new Node();
    third1 = new Node();

    head1->data = "Чайник";
    head1->next = second1;

    second1->data = "Стілець";
    second1->next = third1;

    third1->data = "Ліжко";
    third1->next = nullptr;

    cout << "Original Linked List 1: ";
    printLinkedList(head1);

    Node *head2 = nullptr;
    Node *second2 = nullptr;
    Node *third2 = nullptr;

    head2 = new Node();
    second2 = new Node();
    third2 = new Node();

    head2->data = "Чайник";
    head2->next = second2;

    second2->data = "Стілець";
    second2->next = third2;

    third2->data = "Ліжко";
    third2->next = nullptr;

    cout << "Original Linked List: ";
    printLinkedList(head2);

    head1 = reverseLinkedList(head1);
    cout << "Reversed Linked List: ";
    printLinkedList(head1);

    bool areIdentical = compareLinkedLists(head1, head2);

    cout << "Are the linked lists identical? " << (areIdentical ? "Yes" : "No") << endl;

    return 0;
}