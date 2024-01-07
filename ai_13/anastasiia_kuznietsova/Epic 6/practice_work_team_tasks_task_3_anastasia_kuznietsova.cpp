#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

Node *add(Node *n1, Node *n2)
{
    Node *result = nullptr;
    Node *current = nullptr;
    Node *prev = nullptr;
    int number = 0;
    int sum = 0;

    while (n1 != nullptr || n2 != nullptr || number > 0)
    {
        sum = number + (n1 ? n1->value : 0) + (n2 ? n2->value : 0);
        number = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        current = new Node(sum);

        if (result == nullptr)
        {
            result = current;
        }
        else
        {
            prev->next = current;
        }
        prev = current;
        if (n1)
        {
            n1 = n1->next;
        }
        if (n2)
        {
            n2 = n2->next;
        }
    }
    return result;
}

int main()
{
    Node *head1 = new Node(4);
    head1->next = new Node(2);
    head1->next->next = new Node(6);
    head1->next->next->next = new Node(2);

    Node *head2 = new Node(0);
    head2->next = new Node(4);
    head2->next->next = new Node(1);
    head2->next->next->next = new Node(3);

    Node *result = add(head1, head2);

    while (result != nullptr)
    {
        cout << result->value << ' ';
        Node *temp = result;
        result = result->next;
    }

    return 0;
}