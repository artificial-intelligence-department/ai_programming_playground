#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

typedef struct node
{
    node *previous;
    char *data;
    node *next;
} node;

typedef struct List
{
    node *head;
    node *tail;
} List;

node *Create(const char *value)
{
    // Creates the head node of a doubly linked list
    node *ptr = new node;
    ptr->previous = nullptr;
    ptr->data = strdup(value);
    ptr->next = nullptr;
    return ptr;
}

node *InsertAtFront(node *head, const char *value)
{
    // Inserts a new node at the beginning of a doubly linked list
    if (head == nullptr)
    {
        return Create(value);
    }

    node *ptr = new node;
    ptr->previous = nullptr;
    ptr->data = strdup(value);
    ptr->next = head;
    head->previous = ptr;
    head = ptr;
    return head;
}

node *InsertAtEnd(node *head, const char *value)
{
    // Inserts a new node at the end of a doubly linked list.
    if (head == nullptr)
    {
        return Create(value);
    }
    node *ptr1 = head;
    node *ptr2 = new node;
    ptr2->previous = nullptr;
    ptr2->data = strdup(value);
    ptr2->next = nullptr;

    while (ptr1->next != nullptr)
        ptr1 = ptr1->next;

    ptr1->next = ptr2;
    ptr2->previous = ptr1;

    return head;
}

node *DeleteNodeAtPosition(node *head, int position)
{
    if (head == nullptr)
    {
        cout << "The list is empty. Cannot delete from an empty list.\n";
        return head;
    }

    if (position <= 0)
    {
        cout << "Invalid position. Position should be a positive integer.\n";
        return head;
    }

    node *current = head;
    if (position == 1)
    {
        head = head->next;
        if (head != nullptr)
            head->previous = nullptr;
        free(current->data); // Free the memory for data
        delete current;
        return head;
    }

    int currentPosition = 1;
    while (currentPosition < position && current != nullptr)
    {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr)
    {
        cout << "Position exceeds the length of the list.\n";
        return head;
    }

    if (current->next != nullptr)
        current->next->previous = current->previous;

    if (current->previous != nullptr)
        current->previous->next = current->next;

    free(current->data); // Free the memory for data
    delete current;
    return head;
}

void Print(node *head)
{
    // Prints elements of a doubly linked list from head to tail
    if (head == nullptr)
    {
        cout << "Empty list\n";
        return;
    }

    node *ptr = head;
    cout << "The linked list: ";
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void Fillinfile(node *head, const char *filename)
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cerr << "Error opening file" << endl;
        return;
    }

    node *traverser = head;
    while (traverser != nullptr)
    {
        fout << traverser->data << " ";
        traverser = traverser->next;
    }
    fout.close();
}

node* PurifyList(node *head)
{
    node* temp = new node();
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    return nullptr;
}

node *OutputFile(const char *filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Error opening file" << endl;
        return nullptr;
    }
    node *head = nullptr;
    string content;
    while (fin >> content)
    {
        head = InsertAtEnd(head, content.c_str());
    }
    fin.close();
    return head;
}
int main()
{
    const char *a = "1";
    const char *b = "2";
    const char *c = "3";
    const char *d = "4";
    const char *e = "5";
    const char *f = "6";
    node *head = Create(a);
    head = InsertAtFront(head, c);
    head = InsertAtFront(head, b);
    head = InsertAtFront(head, a);
    head = InsertAtEnd(head, d);
    head = InsertAtEnd(head, e);
    head = InsertAtEnd(head, f);
    Print(head);
    head = DeleteNodeAtPosition(head, 3);
    Print(head);
    Fillinfile(head, "File.txt");
    head = PurifyList(head);
    Print(head);
    head = OutputFile("File.txt");
    Print(head);
    return 0;
}