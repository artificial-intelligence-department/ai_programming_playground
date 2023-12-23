#include <iostream>

struct Node 
{
    int data;
    Node *next;
};

typedef Node* NodePtr;
using namespace std;
NodePtr createList() 
{
    return nullptr;
}
void insert(NodePtr& head,int data)
{
    NodePtr tempPtr;
    tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->next = head;
    head = tempPtr;
}

NodePtr reverse(NodePtr head) 
{
    NodePtr current = head;
    NodePtr prev = nullptr;
    NodePtr next = nullptr;

    while (current != nullptr) 
    {
        next = current->next; 
        current->next = prev;  
        prev = current;        
        current = next;       
    }

    return prev; 
}

void printList(NodePtr head) 
{
    NodePtr current = head;
    if(current==nullptr)
    {
        cout<<"List is empty";
    }
    
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

int main() 
{
    NodePtr myList = createList();
    insert(myList,2);
    insert(myList,4);
    insert(myList,9);

    std::cout << "Original List: ";
    printList(myList);

    NodePtr reversedList = reverse(myList);

    std::cout << "Reversed List: ";
    printList(reversedList);
    
    return 0;
}