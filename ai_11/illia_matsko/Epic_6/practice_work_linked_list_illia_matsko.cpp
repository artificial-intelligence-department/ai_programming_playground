#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int size(Node* head)
{
    Node* current = head;
    int size = 0;
    while (current != head->prev)
    {
        size++;
        current = current->next;
    }
    size++;
    return size;
}

Node* reverse(Node* head)
{
    Node* newHead = new Node;
    Node* newTail = newHead;

    Node* currentData = head->prev;
    newHead->data = currentData->data;
    newHead->next = nullptr;
    newHead->prev = newTail;
    newTail->next = newHead;
    newTail = newHead;
    currentData = currentData->prev;
    while(currentData != head->prev)
    {
        Node* currentInRevList = new Node;
        currentInRevList->data = currentData->data;
        currentInRevList->next = nullptr;
        currentInRevList->prev = newTail;
        newTail->next = currentInRevList;
        newTail = currentInRevList;
        currentData = currentData->prev;
    }
    newHead->prev = newTail;
    newTail->next = newHead;

    return newHead;
}



bool comapre(Node* head1, Node* head2)
{
    int size1 = size(head1);
    int size2 = size(head2);

    if (size1 != size2)
    {
        return false;
    }

    Node* current1 = head1;
    Node* current2 = head2;
    while(current1 != head1->prev)
    {
        if (current1->data != current2->data)
        {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return true;
}

Node* add(Node* head1, Node* head2) {
    Node* sumHead = new Node;
    Node* sumTail = sumHead;

    Node* tail1 = head1->prev;
    Node* tail2 = head2->prev;

    Node* current1 = tail1;
    Node* current2 = tail2;

    vector<int> sum;
    int counter = 0;
    int curr2data = current2->data;
    int curr1data = current1->data;
    if(size(head1) >= size(head2))
    {
        while(current1 != head1)
        {
            if(counter >= size(head2))
            {
                curr2data = 0;
            } else {
                curr2data = current2->data;
            }

            sum.push_back(current1->data + curr2data);
            current1 = current1->prev;
            current2 = current2->prev;
            counter++;
        }
        if(counter >= size(head2))
        {
            curr2data = 0;
        } else {
            curr2data = current2->data;
        }
        sum.push_back(current1->data + curr2data);
    } else {
        while(current2 != head2)
        {
            if(counter >= size(head1))
            {
                curr1data = 0;
            } else {
                curr1data = current1->data;
            }

            sum.push_back(current2->data + curr1data);
            current1 = current1->prev;
            current2 = current2->prev;
            counter++;
        }
        if(counter >= size(head1))
        {
            curr1data = 0;
        } else {
            curr1data = current1->data;
        }
        sum.push_back(current2->data + curr1data);
    }

    for(int i=0; i<sum.size(); i++)
    {
        if(sum[i] > 9)
        {
            sum[i] -= 10;
            if(i+1 == sum.size())
            {
                sum.push_back(1);
            } else {
                sum[i+1] += 1;
            }
        }
    }

    sumHead->next = nullptr;
    sumHead->prev = nullptr;
    for(int i=0; i<sum.size(); i++)
    {
        Node* current = new Node;
        current->data = sum[i];
        current->next = nullptr;
        current->prev = sumTail;
        sumTail->next = current;
        sumTail = current;
    }
    sumHead = sumHead->next;
    sumHead->prev = sumTail;
    sumTail->next = sumHead;

    return sumHead;
}

void print(Node* head)
{
    Node* current = head;
    cout << current->data << " ";
    current = current->next;

    while (current != head)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter list #1: ";

    Node* head1 = new Node;
    Node* tail1 = head1;

    cin >> head1->data;
    head1->next = nullptr;
    head1->prev = nullptr;

    for (int i = 1; i < n; i++) {
        Node* current1 = new Node;
        cin >> current1->data;
        current1->next = nullptr;
        current1->prev = tail1;
        tail1->next = current1;
        tail1 = current1;
    }
    head1->prev = tail1;
    tail1->next = head1;

    //LIST #2
    cout << "Enter k: ";
    cin >> n;
    cout << "Enter list #2: ";

    Node* head2 = new Node;
    Node* tail2 = head2;

    cin >> head2->data;
    head2->next = nullptr;
    head2->prev = nullptr;

    for (int i = 1; i < n; i++) {
        Node* current2 = new Node;
        cin >> current2->data;
        current2->next = nullptr;
        current2->prev = tail2;
        tail2->next = current2;
        tail2 = current2;
    }
    head2->prev = tail2;
    tail2->next = head2;

    cout << endl;

    cout << "Reversed list #1: ";
    print(reverse(head1));
    cout << endl;

    if(comapre(head1, head2))
    {
        cout << "Lists are equal" << endl;
    }
    else
    {
        cout << "Lists are not equal" << endl;
    }
    cout << endl;

    cout << "Sum of lists: ";
    print(add(head1, head2));
}