#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* reverse(Node* head);
bool compare(Node* h1, Node* h2); 
void printList(Node* head);
Node* createList(int length);
Node* add(Node *n1, Node *n2);

int main() 
{
    int length1, length2;

    cout << "Введіть довжину першого списку: ";
    cin >> length1;
    Node* head1 = createList(length1);

    cout << "Введіть довжину другого списку: ";
    cin >> length2;
    Node* head2 = createList(length2);

    cout << "Перший список: ";
    printList(head1);

    cout << "Другий список: ";
    printList(head2);

    if (compare(head1, head2)) 
    {
        cout << "Списки однакові." << endl;
    } 
    else 
    {
        cout << "Списки різні." << endl;
    }

    cout << "Виберіть список, який хочете обернути (1 або 2): ";
    int choice;
    cin >> choice;

    if (choice == 1) 
    {
        head1 = reverse(head1);
    } 
    else if (choice == 2)
    {
        head2 = reverse(head2);
    } 
    else 
    {
        cout << "Невірний вибір." << endl;
    }

    cout << "Обернутий список: ";
    printList(choice == 1 ? head1 : head2);
    
    Node *sum;

    while (head1 != nullptr) 
    {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != nullptr) 
    {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}

Node* reverse(Node* head) 
{
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) 
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

bool compare(Node* h1, Node* h2) 
{
    while (h1 != nullptr && h2 != nullptr) 
    {
        if (h1->data != h2->data) 
        {
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1 == nullptr && h2 == nullptr;
}

void printList(Node* head) 
{
    while (head != nullptr) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* createList(int length) 
{
    Node* head = nullptr;

    cout << "Введіть елементи списку:\n";
    for (int i = 0; i < length; ++i) 
    {
        int value;
        cin >> value;

        if (head == nullptr) 
        {
            head = new Node(value);
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = new Node(value);
        }
    }

    return head;
}

Node* add(Node *n1, Node *n2) 
{
    Node *result = nullptr;
    Node *current = nullptr;
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
        sum = sum % 10;  

        Node *newNode = new Node(sum);

        if (result == nullptr) 
        {
            result = newNode;
            current = result;
        } 
        else 
        {
            current->next = newNode;
            current = newNode;
        }
    }
    return result;
}

