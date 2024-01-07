#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

void printLinkedList(Node *n)
{
    while (n != nullptr)
    {
        cout << n->data;
        if (n->next != nullptr)
        {
            cout << " -> ";
        }
        n = n->next;
    }
    cout << endl;
}

Node *add(Node *n1, Node *n2)
{
    Node *Head_r = nullptr;
    Node *Tail_r = nullptr;
    int carry = 0;

    while (n1 != nullptr || n2 != nullptr || carry != 0)
    {
        int sum = carry;

        if (n1 != nullptr)
        {
            sum += n1->data;
            n1 = n1->next;
        }

        if (n2 != nullptr)
        {
            sum += n2->data;
            n2 = n2->next;
        }

        carry = sum / 10;
        sum %= 10;

        Node *newNode = new Node(sum);

        if (Head_r == nullptr)
        {
            Head_r = newNode;
            Tail_r = Head_r;
        }
        else
        {
            Tail_r->next = newNode;
            Tail_r = newNode;
        }
    }

    return Head_r;
}

int main()
{
    Node *num = new Node(9);
    num->next = new Node(7);
    num->next->next = new Node(3);

    Node *num2 = new Node(2);
    num2->next = new Node(8);

    cout << "Number 1: ";
    printLinkedList(num);

    cout << "Number 2: ";
    printLinkedList(num2);

    Node *sumResult = add(num, num2);

    cout << "Sum: ";
    printLinkedList(sumResult);

    return 0;
}