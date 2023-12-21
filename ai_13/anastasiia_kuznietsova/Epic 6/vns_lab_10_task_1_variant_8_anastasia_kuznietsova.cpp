#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node* prev;
};

Node* createlist(int value)
{
    Node* node = new Node();
    node->value = value;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

void printlist (Node*head)
{
    Node*current=head;
    if(head == nullptr)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    while (current) 
    {
        cout<<current->value<<"\n";
        current = current->next;
    }
}

Node* addfront (Node*&head, int value)
{
    Node* front = new Node();
    front->value = value;
    front->next = head;
    front->prev = nullptr;
    if (head != nullptr)
    {
        head->prev = front;
    }
    head = front;
    return front;
}

Node* deleteafter (Node*head, Node*prev)
{
    if(prev==nullptr || prev->next == nullptr)
    {
        cout<<"The list is empty"<<endl;
        return head;
    }
    Node* todelete = prev->next;
    prev->next = todelete->next;
    if (todelete->next != nullptr)
    {
        todelete->next->prev = prev;
    }
    delete todelete;

    return head;
}

void deletelist(Node*&head)
{
    Node*value = head;
    while (value != nullptr)
    {
        Node* next = value->next;
        delete value;
        value = next;
    }
    head = nullptr;
}

void tofile(Node*head)
{
    ofstream file("From_list.txt");

    if(!file)
    {
        cerr<<"Error while creating file"<<endl;
        exit(1);
    }
    Node* current = head;
    while (current) 
    {
        file<<current->value<<' ';
        current = current->next;
    }
}

void tolist(Node*&head)
{
    ifstream read("From_list.txt");
    if(!read)
    {
        cerr<<"Error while reading file"<<endl;
        exit(2);
    }
    int k;
    while (read>>k) 
    {
        addfront(head, k);
    }
}

int main()
{
    Node* head = createlist(3);
    Node* second = createlist(4);
    Node* third = createlist(5);
    Node* fourth = createlist(1);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    cout<<"List:\n";
    printlist(head);
    cout<<endl;

    cout<<"List after deleting the third element:\n";
    head = deleteafter (head, third);
    printlist(head);
    cout<<endl;

    cout<<"List after adding new elements:\n";
    head = addfront (head, 8);
    addfront (head, 9);
    printlist(head);
    cout<<endl;

    cout<<"After deleting whole list:\n";
    tofile(head);
    deletelist(head);
    printlist(head);
    cout<<endl;

    cout<<"After returning list from file:\n";
    tolist(head);
    printlist (head);
    
    deletelist(head);

return 0;
}