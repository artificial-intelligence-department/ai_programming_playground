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
    while(h1 != nullptr && h2 != nullptr)
    {
        if(h1->data != h2->data) //перевіряю на однаковість даних
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1 == nullptr && h2 == nullptr; //перевіряю на довжину
}

int main()
{
    Node* HEAD1 = new Node(1);
    HEAD1->next = new Node(2);
    HEAD1->next->next = new Node(3);

    Node* HEAD2 = new Node(1);
    HEAD2->next = new Node(2);
    HEAD2->next->next = new Node(3);
    //HEAD2->next->next->next = new Node(4);

    if(compare(HEAD1, HEAD2))
    {
        cout << "The lists are identical!";
    }
    else
    {
        cout << "The lists are different!";
    }

    return 0;
}
