#include <iostream>
#include <random>
using namespace std;

class Node
{
public:
    int Value;
    Node *Next;
    Node *Previous;
    Node(int value, Node *next, Node *prev) : Value(value), Next(next), Previous(prev) {}
    Node() : Next(NULL), Previous(Previous) {}
    Node(int value) : Node(value, NULL, NULL) {}
};

Node *grabTail(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *pHead = head;
    while (pHead->Next != NULL)
        pHead = pHead->Next;
    return pHead;
}

Node *create(int value)
{
    Node *newNode = new Node(value);
    return newNode;
}

Node *push(Node *head, int value)
{
    if (head == NULL)
        return create(value);

    Node *pHead = head;
    Node *pTail = grabTail(head);
    Node *newNode = new Node(value);
    pTail->Next = newNode;
    newNode->Previous = pTail;
    return pHead;
}

Node *pop(Node *head)
{
    Node *pHead = head;
    Node *pTail = grabTail(head);
    pTail->Previous->Next = NULL;
    delete pTail;
    return pHead;
}

Node *deleteList(Node *head)
{
    Node *pHead = head;
    while (pHead != NULL)
    {
        Node *pTemp = pHead;
        pHead = pHead->Next;
        delete pTemp;
    }
    return NULL;
}

void printList(Node *head)
{
    Node *pHead = head;
    while (pHead != NULL)
    {
        cout << pHead->Value << " ";
        pHead = pHead->Next;
    }
    cout << endl;
}

Node *reverse(Node *head)
{
    Node *pCurrent = head, *pNext = head->Next, *pTail = grabTail(head);
    while (pCurrent != NULL)
    {
        // swap next and prev pointers
        swap(pCurrent->Next, pCurrent->Previous);
        pCurrent = pNext;
        if (pNext != NULL)
            pNext = pNext->Next;
    }

    return pTail;
}

// compare two lists
bool compare(Node *h1, Node *h2)
{
    Node *pHead1 = h1;
    Node *pHead2 = h2;
    while (pHead1 != NULL && pHead2 != NULL)
    {
        if (pHead1->Value != pHead2->Value)
            return false;
        pHead1 = pHead1->Next;
        pHead2 = pHead2->Next;
    }
    if (pHead1 != NULL || pHead2 != NULL)
        return false;

    return true;
}

Node *randomList(uniform_int_distribution<int> &d, int size = 10)
{
    random_device rd;
    mt19937 generator(rd());
    Node *head = create(d(generator));
    for (int i = 2; i <= size; i++)
        head = push(head, d(generator));

    return head;
}

Node *add(Node *n1, Node *n2)
{
    Node *pTail1 = grabTail(n1), *pTail2 = grabTail(n2);

    int sum = 0, carry = 0;
    Node *sumList = NULL;

    while (pTail1 != NULL || pTail2 != NULL)
    {
        sum = (pTail1 != NULL ? pTail1->Value : 0) +
              (pTail2 != NULL ? pTail2->Value : 0) +
              carry;
        sumList = push(sumList, sum % 10);
        carry = sum / 10;
        if (pTail1)
            pTail1 = pTail1->Previous;
        if (pTail2)
            pTail2 = pTail2->Previous;
    }

    if (carry != 0)
        sumList = push(sumList, carry);

    sumList = reverse(sumList);
    return sumList;
}

int main()
{
    uniform_int_distribution<> dist(1, 100);
    Node *head1, *head2;

    cout << "Task 1\n";
    head1 = randomList(dist);
    cout << "Before reverse: ";
    printList(head1);
    cout << "After reverse: ";
    head1 = reverse(head1);
    printList(head1);

    cout << "\nTask 2\n";
    head2 = randomList(dist);
    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);
    cout << "Compare: ";
    if (compare(head1, head2))
        cout << "Lists are equal\n";
    else
        cout << "Lists are not equal\n";
    cout << "List 3: ";
    printList(head2);
    cout << "List 4: ";
    printList(head2);
    cout << "Compare: ";
    if (compare(head2, head2))
        cout << "Lists are equal\n";
    else
        cout << "Lists are not equal\n";
    head1 = deleteList(head1);
    head2 = deleteList(head2);

    cout << "\nTask 3\n";
    uniform_int_distribution<> dist2(0, 9);
    head1 = randomList(dist2, 8);
    head2 = randomList(dist2);
    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    cout << "Sum: ";
    Node *sum = add(head1, head2);
    printList(sum);

    head1 = deleteList(head1);
    head2 = deleteList(head2);
    sum = deleteList(sum);
    return 0;
}