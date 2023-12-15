#include <iostream>
#include <fstream>

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
private:
    Node *head;
public:
    LinkedList() {head = NULL;}   // Creating a list.
    void print();
    void pushBack(int);
    void pushFront(int);
    void deleteNode(int);
    void addBefore(int, int);
    void saveToFile(string);
    void loadFromFile(string);
    void deleteLList();
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
void LinkedList::pushFront(int x)
{   
    Node *newNode = new Node(x);

    newNode->next = head;
    head = newNode;
    return;
};
void LinkedList::deleteNode(int key)
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    int index = 1;
    Node *temp = head;
    Node *tempOld = head;

    if(key == 0)
    {
        head = temp->next;
        delete temp;
        return;
    }
    
    temp = temp->next;

    while(temp)
    {
        if(index == key)
        {
            tempOld->next = temp->next;
            delete temp;
            return;
        }
        index++;
        tempOld = temp;
        temp = temp->next;
    }

    cout << "Index out of range\n";
    return;
}
void LinkedList::addBefore(int x, int key)
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    int index = 1;
    Node *temp = head;
    Node *tempOld = head;
    Node *newNode = new Node(x);

    if(key == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = temp->next;

    while(temp)
    {
        if(index == key)
        {
            newNode->next = temp;
            tempOld->next = newNode;
            return;
        }
        index++;
        tempOld = temp;
        temp = temp->next;
    }

    cout << "Index out of range\n";

    return;
}
void LinkedList::saveToFile(string name)
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    fstream file;

    file.open(name, ios::out);

    Node *temp = head;
    while(temp)
    {
        file << temp->data << " ";
        temp = temp->next;
    }
    return;
}
void LinkedList::loadFromFile(string name)
{
    fstream file;
    int x;

    file.open(name, ios::in);

    while(file >> x)
    {
        this->pushBack(x);
    }
    return;
}
void LinkedList::deleteLList()
{
    if(head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    Node *tempNext = head;
    
    while(tempNext)
    {
        temp = tempNext;
        tempNext = tempNext->next;
        delete temp;
    }
    head = NULL;

    return;
}

int main()
{
    LinkedList ll;
    int key, x, n = 110;

    while(n -= 10)
    {
        ll.pushFront(n);
    }
    ll.print();

    cout << "Key of element to delete: ";
    cin >> key;

    ll.deleteNode(key);
    ll.print();

    cout << "Key of element to add before: ";
    cin >> key;
    cout << "Data to add: ";
    cin >> x;

    ll.addBefore(x, key);
    ll.print();

    ll.saveToFile("Linked_list.txt");

    ll.deleteLList();
    ll.print();

    ll.loadFromFile("Linked_list.txt");
    ll.print();

    ll.deleteLList();

    return 0;
}
