#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main()
{
    int n;
    cin >> n;

    Node* head = new Node;
    Node* tail = head;

    cin >> head->data;
    head->next = nullptr;
    head->prev = nullptr;

    for (int i = 1; i < n; i++) {
        Node* current = new Node;
        cin >> current->data;
        current->next = nullptr;
        current->prev = tail;
        tail->next = current;
        tail = current;
    }
    head->prev = tail;
    tail->next = head;

    int k, counter = 0;
    cin >> k;
    cout << "Output from k in left direction: " << endl;
    Node* from = head;
    while(k>1)
    {
        from = from->next;
        counter++;
        k--;
    }
    k+=counter;

    for(int i=0; i<n; i++)
    {
        cout << from->data << " ";
        from = from->prev;
    }
    cout << endl;

    int max = head->data;
    Node* elem = head;
    for(int i=0; i<n; i++)
    {
        if(elem->data > max)
        {
            max = elem->data;
        }
        elem = elem->next;
    }

    counter=0;
    elem = head;
    for(int i=0; i<n; i++)
    {
        if(elem->data == max)
        {
            if(elem == head)
            {
                head = head->next;
                head->prev = tail;
                counter++;
            } else if(elem == tail)
            {
                tail = tail->prev;
                tail->next = head;
                counter++;
            } else {
                elem->prev->next = elem->next;
                elem->next->prev = elem->prev;
                counter++;
            }
        }
        elem = elem->next;
    }

    from = head;
    while(k>1)
    {
        from = from->next;
        k--;
    }
    cout << "Output from k in right direction: " << endl;
    for(int i=0; i<n-counter; i++)
    {
        cout << from->data << " ";
        from = from->next;
    }
    return 0;
}