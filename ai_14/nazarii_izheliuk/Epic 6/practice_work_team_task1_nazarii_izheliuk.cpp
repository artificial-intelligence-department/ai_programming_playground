#include<iostream>

using namespace std;

struct Node
{   
    int data;
    Node* next;
};

void show(Node* head){
    Node* curent = head;
    
    while(curent != nullptr){
        cout << curent->data << " ";
        curent = curent->next;

    }
}

Node* reverse(Node* head) {
    Node *prev = nullptr, *current = head, *nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main(){
    Node* head = nullptr;

    head = new Node{3, nullptr};
    head->next = new Node{5, nullptr};
    head->next->next = new Node{45, nullptr};
    head->next->next->next = new Node{11, nullptr};
    show(head);
    head = reverse(head);
    cout << endl;
    show(head); 
    return 0;
}