#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->value << ' ';
        head = head->next;
    }
    cout << endl;
}

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *current = head;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main()
{
    cout << "Enter the amount of elements: \n";
    int amount;
    cin >> amount;

    Node *head = nullptr;
    Node *tail = nullptr;

    cout << "List the elements: \n";
    for (int i = 0; i < amount; i++)
    {
        int element;
        cin >> element;

        Node *newelement = new Node(element);
        if (head != nullptr)
        {
            tail->next = newelement;
            tail = newelement;
        }
        else
        {
            head = newelement;
            tail = newelement;
        }
    }

    cout << "\nBefore the reverse\n";
    printList(head);

    head = reverse(head);
    cout << "After the reverse\n";
    printList(head);

    return 0;
}