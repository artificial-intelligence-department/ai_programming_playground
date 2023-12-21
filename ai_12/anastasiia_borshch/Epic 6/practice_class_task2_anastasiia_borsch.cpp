#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value) :  data(value), next(nullptr) {};
};

bool compare(Node* h1, Node* h2)
{
    while (h1 && h2)
    {
        if (h1->data != h2->data)
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return !h1 && !h2;
}

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(2);
    head2->next = new Node(2);
    head2->next->next = new Node(1);

    if (compare(head1, head2))
    {
        cout << "The lists are identical";
    }
    else
    {
        cout << "The lists are different";
    }

    return 0;
}
