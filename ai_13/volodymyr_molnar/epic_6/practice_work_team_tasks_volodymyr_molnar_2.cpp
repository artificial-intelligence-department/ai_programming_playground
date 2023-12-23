#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

bool compare(Node* h1, Node* h2);
int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    if (!compare(head1, head2)) 
        cout << "lists not rivni." << endl;
    else
        cout << "lists is rivni." << endl;

    delete head2;
    delete head1;
    return 0;
}

bool compare(Node* h1, Node* h2)
{
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->data != h2->data)
            return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1 != nullptr || h2 != nullptr)
        return false;
    return true;
}
