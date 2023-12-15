#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};
typedef Node* nodeptr;
nodeptr createList() 
{
    return nullptr;
}
void printList(nodeptr head) 
{
    nodeptr current = head;
    if(current==nullptr)
    {
        cout<<"List is empty";
    }
    
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->link;
    }

    cout << endl;
}
void insert(nodeptr& head,int data)
{
    nodeptr tempPtr;
    tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->link = head;
    head = tempPtr;
}
void writeToFile(nodeptr head, const string& filename) 
{
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Unable to open the file: " << filename << endl;
        return;
    }

    nodeptr current = head;

    while (current != nullptr) {
        outFile << current->data << " ";
        current = current->link;
    }

    outFile.close();
}
nodeptr restoreFromFile(const string& filename)
{
    ifstream inFile(filename);

    if (!inFile) 
    {
        cerr << "Unable to open the file: " << filename << endl;
        return nullptr;
    }

    nodeptr head = createList();
    int data;

    while (inFile >> data) 
    {
        insert(head, data);
    }

    inFile.close();
    return head;
}
void deleteList(nodeptr& head) 
{
    while (head != nullptr) 
    {
        nodeptr temp = head;
        head = head->link;
        delete temp;
    }
}
void addNode(nodeptr& head, int data, int position)
{
    nodeptr newNode = new Node;
    newNode->data = data;

    if (position == 1 || head == nullptr)
    {
        newNode->link = head;
        head = newNode;
    }
    else
    {
        nodeptr temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; ++i)
            temp = temp->link;

        if (temp != nullptr)
        {
            newNode->link = temp->link;
            temp->link = newNode;
        }
        else
        {
            cout << "Invalid position to insert." << endl;
        }
    }
}
void deleteNode(Node **head, int position)
{
    if (*head == nullptr)
    {
        cout << "List is already empty!" << endl;
        return;
    }

    Node *current = *head;
    Node *previous = nullptr;

    if (position == 1)
    {
        *head = current->link;
        delete current;
        current = nullptr;
    }
    else
    {
        for (int i = 1; i < position && current != nullptr; ++i)
        {
            previous = current;
            current = current->link;
        }

        if (current == nullptr)
        {
            cout << "Invalid position to delete." << endl;
            return;
        }

        previous->link = current->link;

        delete current;
        current = nullptr;
    }
}

int main()
{
    int pos_to_add,number_to_add,pos_to_delete;
    cout<<"Enter pos to add: ";
    cin>>pos_to_add;
    cout<<"Enter number to add: ";
    cin>>number_to_add;
    cout<<"Enter pos to delete: ";
    cin>>pos_to_delete;
    nodeptr head = createList();
    insert(head,228);
    insert(head,17);
    insert(head,35);
    insert(head,44);
    printList(head);

     addNode(head,number_to_add,pos_to_add);
    printList(head);

     deleteNode(&head,pos_to_delete);
    printList(head);

    writeToFile(head,"test.txt");
    deleteList(head);
    printList(head);

    head=restoreFromFile("test.txt");
    printList(head);
    
}