#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

bool compare(Node *h1, Node *h2)
{
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->value != h2->value)
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1 == nullptr && h2 == nullptr)
    {
        return true;
    }

    return false;
}

int main()
{
    Node *head1 = new Node(4);
    head1->next = new Node(2);
    head1->next->next = new Node(9);

    Node *head2 = new Node(4);
    head2->next = new Node(2);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(5);

    if(compare(head1, head2)==true)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    
    return 0;
}