#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *nextnumber;

    Node(int val) : data(val), nextnumber(nullptr) {}
};
Node *reverse(Node *head)
{
    Node *nextnumber = nullptr;
    Node *currentnumber = head;
    Node *previousnumber = nullptr;

    while (currentnumber != nullptr)
    {
        nextnumber = currentnumber->nextnumber;
        currentnumber->nextnumber = previousnumber;
        previousnumber = currentnumber;
        currentnumber = nextnumber;
    }

    return previousnumber;
}
void printList(Node *head)
{
    Node *currentnumber = head;
    while (currentnumber != nullptr)
    {
        cout << currentnumber->data << " ";
        currentnumber = currentnumber->nextnumber;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->nextnumber = new Node(2);
    head->nextnumber->nextnumber = new Node(3);
    head->nextnumber->nextnumber->nextnumber = new Node(4);
    head->nextnumber->nextnumber->nextnumber->nextnumber = new Node(5);

    cout << "List: ";
    printList(head);

    head = reverse(head);

    cout << "List after reversion: ";
    printList(head);

    return 0;
}
