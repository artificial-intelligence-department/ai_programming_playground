#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

class LinkedList
{ 
public:
    Node* head;

    LinkedList() {head = NULL;}   // Creating a list.
    void print();
    void pushFront(int);
    void pushBack(int);
    void reverse();
};

void LinkedList::print()
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return;
}
void LinkedList::pushFront(int x)
{   
    Node *newNode = new Node(x);

    newNode->next = head;
    head = newNode;
    return;
};
void LinkedList::pushBack(int x)
{
    Node *newNode = new Node(x);
    
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    Node *temp = head;

    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return;
}
void LinkedList::reverse()
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    head = prev;

    return;
}
bool compare(LinkedList &h1, LinkedList &h2);
Node* add(LinkedList &n1, LinkedList &n2);

int main()
{  
    LinkedList ll;

    cout << "TASK 1\n\n";

    int n = 110;

    while(n -= 10)
    {
        ll.pushFront(n);
    }
    ll.print();

    ll.reverse();
    ll.print();

    cout << "\nTASK 2\n\n";
    LinkedList llSecond;

    for(int i = 10; i <= 100; i += 10)
    {
        llSecond.pushFront(i);
    }

    ll.print();
    llSecond.print();

    cout << (compare(ll, llSecond) ? "true" : "false") << endl;

    cout << "\nTASK 3\n\n";

    LinkedList num1;
    num1.pushFront(8);
    num1.pushFront(3);
    num1.pushFront(7);
    num1.pushFront(9);

    LinkedList num2;
    num2.pushFront(2);
    num2.pushFront(6);
    num2.pushFront(5);
    num2.pushFront(8);

    num1.print();
    cout << "+\n";
    num2.print();

    LinkedList sum;
    sum.head = add(num1, num2);

    sum.print();

    return 0;
}

bool compare(LinkedList &h1, LinkedList &h2)
{
    Node *head1 = h1.head;
    Node *head2 = h2.head;
    while(true)
    {
        if(head1->data != head2->data)
        {
            return false;
        }
        if(head1->next != NULL )
        {
            head1 = head1->next;

            if(head2->next != NULL)
            {
                head2 = head2->next;
            }
            else
            {
                return  false;
            }
        }
        else if (head2->next == NULL)
        {
            return true;
        }
        else
        {
            return  false;
        }
    }

    return false;
}
Node* add(LinkedList &n1, LinkedList &n2)
{   
    int temp = 0, num1, num2;
    Node *head1 = n1.head;
    Node *head2 = n2.head;

    LinkedList sum;
    
    while(head1 || head2)
    {
        if(head1)
        {
            num1 = head1->data;
        }
        else
        {
            num1 = 0;
        }

        if(head2)
        {
            num2 = head2->data;
        }
        else
        {
            num2 = 0;
        }

        temp = num1 + num2 + temp;

        sum.pushBack(temp % 10);

        temp /= 10;

        if(head1)
        {
            head1 = head1->next;
        }
        if(head2)
        {
            head2 = head2->next;
        }
    }

    if(temp)
    {
        sum.pushBack(temp);
    }

    return sum.head;
}
