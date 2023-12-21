#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

void printlist(Node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void insertfront(Node*& head, int NewValue){
    Node* NewNode = new Node;
    NewNode->data = NewValue;

    NewNode->next = head;

    head = NewNode;
}

void insertend(Node*& head, int NewValue){
    Node* NewNode = new Node;
    NewNode->data = NewValue;
    NewNode->next = NULL;

    if (head == NULL){
        head = NewNode;
        return;
    }
    
    Node* last = head;
    while (last->next != NULL){
        last = last->next;
    }
    
    last->next = NewNode;
}

void insertmiddle(Node* node, int pos, int NewValue){
    for (int i = 1; i < pos; i++){
        node = node->next;
    }
    
    Node* NewNode = new Node;
    NewNode->data = NewValue;

    NewNode->next = node->next;
    node->next = NewNode;
}
Node* createlist(int size){
    Node* head = NULL;
    Node* current = NULL;

    for (int i = 0; i < size; i++){
        Node* NewNode = new Node;
        NewNode->data = i + 1;
        NewNode->next = NULL;

        if (head == NULL){
            head = NewNode;
            current = NewNode;
        } 
        else{
            current->next = NewNode;
            current = NewNode;
        }
    }
    
    return head;
}

int main(){
    int size = 4;

    Node* head = createlist(size);
    cout << "before changes: ";
    printlist(head);

    insertmiddle(head, 3, -1);
    insertfront(head, -1);
    insertend(head, -1);

    cout << "after changes: ";
    printlist(head);

    return 0;
}